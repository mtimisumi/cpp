#include "PmergeMe.hpp"

template<typename Container>
void binaryInsert(Container& c, element& e, int index)
{
	if (index == 0)
	{
		c.insert(c.begin(), e);
		return ;
	}

	size_t low = 0;
	size_t high = index;

	while (low < high)
	{
		size_t mid = low + (high-low)/2;

		if (c[mid] >= e)
			high = mid;
		else 
			low = mid + 1;

		++comparisons;
	}

	c.insert(c.begin() + low, e);
}

const int JacobSthal[] = { 0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};

template<typename Container>
Container JacobSthalSort(Container& c, element& saved)
{
	Container pairsToSort;
	for (element e : c)
		pairsToSort.push_back(*(e.pair));
	if (saved.value != -1)
		pairsToSort.push_back(saved);

	for (element& e : c)
		e = *(e.prev);

	// printContainer(pairsToSort, "pairs to sort:\n");
	// printContainer(c, "winners:\n");

	int jacob = 1;
	int shift = 0;
	bool done = false;
	while (!done)
	{
		// get k index according to jacob
		int k = JacobSthal[jacob];

		// std::cout << "k: " << k << "\n";
		// std::cout << "pairsToSort size: " << pairsToSort.size() << "\n";

		if (static_cast<size_t>(k) > pairsToSort.size())
			k = pairsToSort.size();
		if (static_cast<size_t>(k) == pairsToSort.size())
			done = true;

		int index = k-1+shift;
		for (int a = JacobSthal[jacob-1]; a < k; k--)
		{
			// std::cout << "\nk : " << k << "\n";
			// std::cout << "shift: " << shift << "\n";
			// std::cout << "index: " << index << "\n";
			// std::cout << "a: " << a << "\n";

			// element cur_element = c[index];
			element to_insert = pairsToSort[k-1];
			element next_element = c.back();
			if (index-1 > a-1)
				next_element = c[index-1];

			// std::cout << "cur_element: " << cur_element.value << "\n";
			// std::cout << "to_insert: " << to_insert.value << "\n";
			// std::cout << "next_element: " << next_element.value << "\n";

			binaryInsert(c, to_insert, index);

			if (to_insert <= next_element)
				index++;

			shift++;

			// printContainer(c, "c after sort:\n");
		}
		jacob++;
	}

	// printContainer(c, "c after sorting all:\n");

	return c;
}

template<typename Container>
Container mergeInsertionSort(Container& elements)
{
	element saved = {-1, NULL, NULL};

	if (startSorting(elements, saved))
		return elements;

	Container biggestFromElements = getBiggestFromElements(elements, saved);
	// printContainer(biggestFromElements, "biggest of pairs:\n");
	Container sortedBiggest = mergeInsertionSort(biggestFromElements);
	// printContainer(sortedBiggest, "sorted biggest:\n");
	Container sortedAll = JacobSthalSort(sortedBiggest, saved);
	// printContainer(sortedAll, "sorted all:\n");

	return sortedAll;
}

template<typename Container>
Container getBiggestFromElements(Container& elements, element& saved)
{
	Container biggestFromElements;
	element biggest;
	size_t biggest_i, smallest_i;

	for (size_t i = 0; i < elements.size(); i++, i++)
	{
		if (i == elements.size()-1)
		{
			saved = elements[i];
			break ;
		}

		++comparisons;
		biggest_i = elements[i] > elements[i+1] ? i : i+1;
		smallest_i = elements[i] <= elements[i+1] ? i : i+1;
		
		biggest = elements[biggest_i];
		biggest.pair = &(elements[smallest_i]);
		biggest.prev = &(elements[biggest_i]);
		
		biggestFromElements.push_back(biggest);
	}

	return biggestFromElements;
}

template<typename Container>
bool startSorting(Container& elements, element& saved)
{
	if (elements.size() > 3)
		return false;

	if (elements.size() == 1)
		return true;

	++comparisons;
	if (elements[0] > elements[1])
		std::swap(elements[0], elements[1]);

	if (elements.size() == 3)
	{
		saved = elements.back();
		elements.pop_back();
		binaryInsert(elements, saved, 2);
	}

	return true;
}


template<typename Container>
void printContainer(Container& c, const std::string& msg)
{
	std::cout << msg;
	for (element e : c)
		std::cout << e.value << " ";
	std::cout << "\n";
}