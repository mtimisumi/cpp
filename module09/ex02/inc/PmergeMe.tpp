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

		// ++comparisons;
		if (c[mid] > e)
			high = mid;
		else 
			low = mid + 1;
	}

	c.insert(c.begin() + low, e);
}

template<typename Container>
void printContainer(Container& c, const std::string& msg)
{
	std::cerr << msg << ":\n";
	for (element e : c)
		std::cerr << e.value << " ";
	std::cerr << "\n\n";
}

const int JacobSthal[] = { -1, 0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};

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

	int index = 0;
	int jacob = 1;
	bool done = false;
	while (!done)
	{
		int k = JacobSthal[jacob];

		if (static_cast<size_t>(k) > pairsToSort.size()-1)
			k = pairsToSort.size()-1;
		if (static_cast<size_t>(k) == pairsToSort.size()-1)
			done = true;
		
		for (int a = JacobSthal[jacob-1]; a < k; k--)
		{
			element at_index = {-1, NULL, NULL};
			if (static_cast<size_t>(k+index) < c.size())
				at_index = c[k+index];
			binaryInsert(c, pairsToSort[k], k+index);
			if (pairsToSort[k] <= at_index)
				index++;
		}
		jacob++;
	}

	return c;
}

template<typename Container>
Container mergeInsertionSort(Container& elements)
{
	if (startSorting(elements))
		return elements;

	element saved = {-1, NULL, NULL};
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
bool startSorting(Container& elements)
{
	if (elements.size() > 2)
		return false;

	if (elements.size() == 2 && elements[0] > elements[1])
		std::swap(elements[0], elements[1]);

	return true;
}
