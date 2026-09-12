#include "PmergeMe.hpp"

template<typename Container>
Container mergeInsertionSort(Container& elements)
{
	if (startSorting(elements) == true)
		return elements;

	element saved;
	Container biggestFromElements = getBiggestFromElements(elements, saved);
	const Container sorted = mergeInsertionSort(biggestFromElements);
	Container insertToSorted = sorted;

	for (element& e : insertToSorted)
		e = *(e.prev);

	for (element e : sorted)
	{
		element toInsert = elements[e.pair_index];
		insertElement(insertToSorted, toInsert);
	}
	if (elements.size() % 2 == 1)
		insertElement(insertToSorted, saved);

	return insertToSorted;
}

template<typename Container>
Container getBiggestFromElements(const Container& elements, element& saved)
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
		smallest_i = elements[i] < elements[i+1] ? i : i+1;

		biggest = elements[biggest_i];
		biggest.pair_index = smallest_i;
		biggest.prev = &(elements[biggest_i]);

		biggestFromElements.push_back(biggest);
	}

	return biggestFromElements;
}

template<typename Container>
void insertElement(Container& insertToSorted, element toInsert)
{
    for (size_t i = 0; i < insertToSorted.size(); i++)
    {
        if (toInsert.value < insertToSorted[i].value)
        {
            insertToSorted.insert(insertToSorted.begin() + i, toInsert);
            return;
        }
    }

    insertToSorted.push_back(toInsert);
}

template<typename Container>
void printContainer(Container& c, const std::string& msg)
{
	std::cout << "Printing " << msg << ":\n";
	for (element e : c)
		std::cout << e.value << " ";
	std::cout << "\n\n";
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