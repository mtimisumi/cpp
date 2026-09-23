#include "PmergeMe.hpp"

template<typename Container>
int binaryInsert(Container& c, element& e, int index)
{
	if (index == 0)
	{
		c.insert(c.begin(), e);
		return 0;
	}

	int low = 0;
	int high = index;

	while (low < high)
	{
		int mid = low + (high-low)/2;

		if (c[mid] >= e)
			high = mid;
		else 
			low = mid + 1;

		++comparisons;
	}

	c.insert(c.begin() + low, e);

	return low;
}

const int JacobSthal[] = { 0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731};

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

	std::vector<int> cIndex;
	for (size_t i = 0; i < pairsToSort.size(); i++)
		cIndex.push_back(i);

	int jacob = 1;
	bool done = false;
	while (!done)
	{
		int k = JacobSthal[jacob];

		if (static_cast<size_t>(k) > pairsToSort.size())
			k = pairsToSort.size();
		if (static_cast<size_t>(k) == pairsToSort.size())
			done = true;

		for (int a = JacobSthal[jacob-1], i = k-1; a < k; k--, i--)
		{
			element pair = pairsToSort[i];
			element next = c.back();
			if (i-1 > a-1)
				next = c[i-1];

			int pairIndex = binaryInsert(c, pair, cIndex[i]);
			updateCIndex(cIndex, pairIndex);
		}
		jacob++;
	}

	return c;
}

template<typename IndexContainer>
void updateCIndex(IndexContainer& cIndex, int pairIndex)
{
	for (size_t i = 0; i < cIndex.size(); i++)
	{
		if (cIndex[i] < pairIndex)
			continue ;

		cIndex[i]++;
	}
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
	std::cout << msg;

	for (size_t i = 0; i < SHOW_NUMBERS; i++)
	{
		if (i == c.size())
			break ;

		std::cout << c[i] << " ";
	}

	if (c.size() > SHOW_NUMBERS)
		std::cout << "[...]";

	std::cout << "\n";
}



template<typename Container>
bool isSorted(Container& c)
{
	if (c.size() < 2)
		return true;

	std::vector<element>::iterator it = c.begin();
	std::vector<element>::iterator next = std::next(it);

	for (; next != c.end(); it++, next++)
	{
		if (*it > *next)
			return false;
	}

	return true;
}