#include "PmergeMe.hpp"



// still have to take care of growing index
template<typename Container> void binaryInsert(Container& c, element& e, int index)
{
	int mid = index/2;

	if (e.value > c[mid].value)
		binaryInsert(c, e, mid+(mid/2));
	else
		binaryInsert(c, e, mid-(mid/2));
	
}

const int JacobSthal[] = { 0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};

template<typename Container> void JacobsthalSort(const Container& example, const Container& elements)
{
	Container c = example;
	for (element& e : c)
		c = *(c.prev);

	int index = 0;
	bool done = false;
	while (!done)
	{
		int k = JacobSthal[index];
		if (k == 0)
			c.insert(*(elements[0].pair));
		if (k > c.size()-1)
		{
			k = c.size()-1;
			done = true;
		}
		if (k > 0)
		{
			int a = JacobSthal[k-1];
			for (int i = a; a < k; k--)
				binaryInsert(c, *(elements[k].pair), index);
		}
		index++:
	}
}


template<typename Container> void JacobsthalSort(Container& c, const Container& example)
{
	int jacob_index = 0;
	bool done = false;

	while (!done)
	{
		int k = JacobSthal[jacob_index];
		if (k > example.size()-1)
		{
			k = example.size()-1;
			done = true;
		}
		if (k == 0)
			c.insert();

		for (int i = JacobSthal[k-1]; )


		for (int i = k-1; i >= 0; i--)
		{
			for()
			binaryInsert(c, i, k);
		}
	}
}


template<typename Container>
Container mergeInsertionSort(Container& elements)
{
	if (startSorting(elements) == true)
		return elements;

	element saved;
	Container biggestFromElements = getBiggestFromElements(elements, saved);
	const Container sorted = mergeInsertionSort(biggestFromElements);

	Container c = JacobSthalSort(sorted);

	Container c = sorted;

	for (element& e : c)
		e = *(e.prev);

	JacobSthalSort();

	JacobsthalOrderSort(c, );
	// sort();
	if (elements.size() % 2 == 1)
		insertElement(c, saved);

	return c;
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
		smallest_i = elements[i] <= elements[i+1] ? i : i+1;

		biggest = elements[biggest_i];
		// biggest.pair_index = smallest_i;
		biggest.pair = &(elements[smallest_i]);
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
bool startSorting(Container& elements)
{
	if (elements.size() > 2)
		return false;

	if (elements.size() == 2 && elements[0] > elements[1])
		std::swap(elements[0], elements[1]);

	return true;
}

template<typename Container>
void printContainer(Container& c)
{

}