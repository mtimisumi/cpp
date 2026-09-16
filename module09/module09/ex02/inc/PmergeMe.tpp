#include "PmergeMe.hpp"

template<typename Container>
void binaryInsert(Container& c, element& e, int index)
{
	(void)index;
	for (size_t i = 0; i < c.size(); i++)
	{
		if (e < c[i])
			continue ;
		c.insert(e, i);
		break ;
	}
}

const int JacobSthal[] = { 0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};

template<typename Container>
Container JacobsthalSort(const Container& example, element& saved)
{
	Container c = example;
	for (element& e : c)
		e = *(e.prev);

	int index = 0;
	int jacob = 0;
	bool done = false;
	while (!done)
	{
		int k = JacobSthal[jacob];
		if (k == 0) {
			c.insert(c.begin(), *(example[0].pair));
			index++;
		}
		if (k > 0) {
			if (k > example.size()-1)
				k = example.size()-1;
			if (k == example.size(-1))
				done = true;

			for (int a = JacobSthal[k-1]; a < k; k--)
			{
				pair = *(example[k].pair);
				binaryInsert(c, pair, k+index);
				if (pair <= example[k])
					index++;
			}
		}
		jacob++;
	}

	if (example.size()%2 == 1)
		binaryInsert(c, saved, example.size()-1);
}

template<typename Container>
Container mergeInsertionSort(Container& elements)
{
	if (startSorting(elements))
		return elements;

	element saved;
	const Container BiggestFromElements = getBiggestFromElements(elements, saved);
	const Container sortedBiggest = mergeInsertionSort(biggestFromElements);

	return JacobSthalSort(sortedBiggest, saved);
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
		biggest.pair = &(elements[smallest_i]);
		biggest.prev = &(elements[biggest_i]);

		biggestFromElements.push_back(biggest);
	}

	return biggestFromElements;
}

template<typename Container>
bool startSorting(Container& elements)
{
	if (elements.size() < 2)
		std::cout << "SMALLER THAN 2?!\n";

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