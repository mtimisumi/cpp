#include "PmergeMe.hpp"

template<typename Container>
void binaryInsert(Container& c, element& e, int index)
{
	(void)index;
	for (size_t i = 0; i < c.size(); i++)
	{
		if (e <= c[i])
		{
			c.insert(c.begin()+i, e);
			return ;
		}
	}
	c.push_back(e);
}

const int JacobSthal[] = { 0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};

template<typename Container>
Container JacobSthalSort(Container& pairsToSort, element& saved)
{
	Container c = pairsToSort;
	for (element& e : c)
		e = *(e.prev);

	if (saved.value != -1)
		pairsToSort.push_back(saved);

	int index = 0;
	int jacob = 0;
	bool done = false;
	while (!done)
	{
		size_t k = JacobSthal[jacob];
		if (k == 0) {
			c.insert(c.begin(), pairsToSort[0]);
			index++;
		}
		if (k > 0) {
			if (k > pairsToSort.size()-1)
				k = pairsToSort.size()-1;
			if (k == pairsToSort.size()-1)
				done = true;

			for (size_t a = JacobSthal[k-1]; a < k; k--)
			{
				binaryInsert(c, pairsToSort[k], k+index);
				if (pairsToSort[k] <= )
					index++;
			}
		}
		jacob++;
	}

	return c;
}
/*

	2 3 4 5 
	0 1 2 3      saved 8

*/
template<typename Container>
Container mergeInsertionSort(Container& elements)
{
	if (startSorting(elements))
		return elements;

	element saved = {-1, NULL, NULL};
	Container biggestFromElements = getBiggestFromElements(elements, saved);
	Container sortedBiggest = mergeInsertionSort(biggestFromElements);

	Container pairsToSort;
	for (element e : sortedBiggest)
		pairsToSort.push_back(*(e.pair));

	Container sortedAll = JacobSthalSort(pairsToSort, saved);

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
	// if (elements.size() < 2)
	// 	std::cout << "SMALLER THAN 2?!\n";

	if (elements.size() > 2)
		return false;

	if (elements.size() == 2 && elements[0] > elements[1])
		std::swap(elements[0], elements[1]);

	return true;
}

template<typename Container>
void printContainer(Container& c, const std::string& msg)
{
	std::cout << msg << "\n";
	for (element e : c)
		std::cout << e.value << " ";
	std::cout << "\n\n";
}