#include "PmergeMe.hpp"
#include <limits>
#include <string>
#include <exception>
#include <utility>


void parseArguments(PmergeMe& p, int argc, char *argv[])
{
	for (int i = 0; i < argc; i++)
	{
		size_t pos;
		int value;

		try {
			value = std::stoi(argv[i], &pos);
		}
		catch (const std::exception& e) {
			throw std::runtime_error(std::string("argument given is invalid: ") + argv[i]);
		}

		if (pos != std::string(argv[i]).length())
			throw std::runtime_error(std::string("argument given is invalid: ") + argv[i]);
		if (value < 1)
			throw std::runtime_error(std::string("argument given is not positive: ") + argv[i]);

		p.addNumber(value);
	}
}

void insertElement(std::vector<element>& insertToSorted, element toInsert)
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

void printElement(const element& e)
{
	std::cout << "new value:" << e.value << "\n";
	std::cout << "new pair :" << e.pair_index << "\n";
	std::cout << "og value :" << e.prev->value << "\n";
	std::cout << "og pair  :" << e.prev->pair_index << "\n\n";
}

std::vector<element> getBiggestFromElements(const std::vector<element>& elements, element& saved)
{
	std::vector<element> biggestFromElements;
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

void printValue(const std::vector<element>& ew)
{
	for (element e : ew)
		std::cout << e.value << " ";
	std::cout << "\n";
}

bool startSorting(std::vector<element>& elements)
{
	if (elements.size() > 2)
		return false;

	if (elements.size() == 2 && elements[0] > elements[1])
		std::swap(elements[0], elements[1]);

	return true;
}

std::vector<element> mergeInsertionSort(std::vector<element>& elements)
{
	if (startSorting(elements) == true)
		return elements;

	element saved;
	std::vector<element> biggestFromElements = getBiggestFromElements(elements, saved);
	const std::vector<element> sorted = mergeInsertionSort(biggestFromElements);
	std::vector<element> insertToSorted = sorted;

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


// void sortDeque(PmergeMe& p)
// {}



int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Error: Need more arguments\n";
		return 1;
	}

	PmergeMe p;
	try
	{
		parseArguments(p, argc-1, ++argv);
		p.FordJohnsonVector();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	}
}