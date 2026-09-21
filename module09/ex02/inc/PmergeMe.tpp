#include "PmergeMe.hpp"

template<typename Container>
void binaryInsert(Container& c, element& e, int index)
{
	if (index == 1)
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

	int jacob = 1;
	int shift = 0;
	bool done = false;
	while (!done)
	{
		int k = JacobSthal[jacob];

		if (static_cast<size_t>(k) > pairsToSort.size())
			k = pairsToSort.size();
		if (static_cast<size_t>(k) == pairsToSort.size())
			done = true;

		for (int a = JacobSthal[jacob-1]; a < k; k--)
		{
			int target = k+shift-1;
			element at_index = c.back();
			if (static_cast<size_t>(target) < c.size())
				at_index = c[target];

			binaryInsert(c, pairsToSort[k-1], target);
			if (pairsToSort[k-1] <= at_index)
				shift++;
		}
		jacob++;
	}

	return c;
}

template<typename Container>
Container mergeInsertionSort(Container& elements)
{
	element saved = {-1, NULL, NULL};

	if (startSorting(elements, saved))
		return elements;

	Container biggestFromElements = getBiggestFromElements(elements, saved);
	Container sortedBiggest = mergeInsertionSort(biggestFromElements);
	Container sortedAll = JacobSthalSort(sortedBiggest, saved);

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
	std::cerr << msg;
	for (element e : c)
		std::cerr << e.value << " ";
	std::cout << "\n";
}