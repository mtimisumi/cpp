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



void printBiggestFromElements(const std::vector<element>& getBiggestFromElements)
{
	std::cout << "biggestFromElements:\n";
	for (element e : getBiggestFromElements)
		std::cout << e.value << " ";
	std::cout << "\npair position:\n";
	for (element e : getBiggestFromElements)
		std::cout << e.pair_index << " ";
	std::cout << "\nprevious element:\n";
	for (element e : getBiggestFromElements)
		std::cout << e.prev->value << " ";
	std::cout << "\n\n";
}

void printElement(const element& e)
{
	std::cout << "new value:" << e.value << "\n";
	std::cout << "new pair :" << e.pair_index << "\n";
	std::cout << "og value :" << e.prev->value << "\n";
	std::cout << "og pair  :" << e.prev->pair_index << "\n\n";
}

std::vector<element> getBiggestFromElements(const std::vector<element>& elements)
{
	std::vector<element> biggestFromElements;
	element biggest;
	size_t biggest_i, smallest_i;

	for (size_t i = 0; i < elements.size()-1; i++, i++)
	{
		biggest_i = elements[i] > elements[i+1] ? i : i+1;
		smallest_i = elements[i] < elements[i+1] ? i : i+1;

		biggest = elements[biggest_i];
		biggest.pair_index = smallest_i;
		biggest.prev = &(elements[biggest_i]);
		// printElement(biggest);

		biggestFromElements.push_back(biggest);
	}
	// std::cout << "------------\n";

	return biggestFromElements;
}

void printValue(const std::vector<element>& ew)
{
	for (element e : ew)
		std::cout << e.value << " ";
	std::cout << "\n\n";
}

int index = 1;

std::vector<element> mergeInsertionSort(const std::vector<element>& elements)
{
	std::cout << "elements " << index << ":\n";
	index++;
	for (element e : elements)
	{
		std::cout << e.value << " ";
	}
	std::cout << "\n\n";

	if (elements.size() <= 2)
	{
		std::vector<element> toReturn = elements;
		if (toReturn.size() < 2)
		{
			return toReturn;
		}
		if (toReturn[0] > toReturn[1])
			std::swap(toReturn[0], toReturn[1]);
		return toReturn;
	}
	std::vector<element> biggestFromElements = getBiggestFromElements(elements);
	// printing...
	// printBiggestFromElements(biggestFromElements);
	const std::vector<element> sorted = mergeInsertionSort(biggestFromElements);
	std::vector<element> insertToSorted = sorted;
	std::cout << "sorted\n";
	printValue(insertToSorted);

	for (element& e : insertToSorted)
		e = *(e.prev);

	std::cout << "after update\n";
	printValue(insertToSorted);


	for (element e : sorted)
	{
		element toInsert = elements[e.pair_index];
		insertElement(insertToSorted, toInsert);
	}

	std::cout << "sorted:\n";
	for (element e : insertToSorted)
	{
		std::cout << e.value << " ";
	}
	std::cout << "\n\n";
	std::cout << "------------\n";

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