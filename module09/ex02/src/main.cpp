#include "PmergeMe.hpp"
#include <iostream>
#include <limits>
#include <string>
#include <exception>


void parseArguments(PmergeMe& p, int argc, char *argv[])
{
	for (int i = 0; i < argc; i++)
	{
		size_t pos;
		int value;

		try {
			value = std::stoi(argv[i]);
		}
		catch (const std::exception& e) {
			throw std::runtime_error(std::string("argument given is invalid: ") + argv[i]);
		}

		if (pos != std::string(argv[i]).length())
			throw std::runtime_error(std::string("argument given is invalid: ") + argv[i]);
		if (value < 1)
			throw std::runtime_error(std::string("argument given is not positive: ") + argv[i]);

		p.addNumber(value, i);
	}
}

void FordJohnsonVector(PmergeMe& p)
{
	std::vector<element> elements;
	element biggest, smallest;

	for (int i = 0, index = 0; i < p.getSizeVec(); i++, i++, index++)
	{
		if (i == p.getSizeVec())
			break ;

		element a = p.getVec(i);
		element b = p.getVec(i+1);
		biggest = (a > b) ? a : b;
		smallest = (a < b) ? a : b;
		biggest.curr.my_index = 
	}
}

void sortVector(const std::vector<element>& elements)
{
	std::vector<element> biggestFromElements;
	element biggest, smallest;

	for (int i = 0; i < elements.size(); i++, i++)
	{
		if (i == elements.size())
			break ;

		biggest 
	}
}

// void sortVector(const std::vector<element>& v)
// {
// 	std::vector<element> biggestFromPairs;
// 	std::vector<pair> pairs;
// 	element biggest, smallest;

// 	for (int i = 0, index = 0; i < v.size(); i++, i++, index++)
// 	{
// 		if (i == v.size())
// 			break ;

// 		if (v[i] > v[i+1])
// 			biggest = v[i];
// 		else
// 			biggest = v[i+1];

// 		biggest.index = index;
// 		pairs.index = ;
// 		// 3 2 6 7 4 5 8
// 		// 0 1 2 3 4 5 6

// 		// pairs = 0-1, 2-3, 4-5
	
// 		// 3 7 5 8
// 		// 0 3 4 6

// 		// 3 5 7 8
// 		// 0 4 3 6

// 		// ---------------

// 		// 3 5 7 8
// 		// 0 1 2 3

// 		// 5 8
// 		// 1 3
// 		// 0 2
// 	}
// }

void sortDeque(PmergeMe& p)
{

}

// void insertElement(std::vector<element>& insertToSorted, element toInsert)
// {
	
// }

std::vector<element> mergeInsertionSort(const std::vector<element>& elements)
{
	std::vector<element> biggestFromElements;
	element biggest, smallest;
	int biggest_i, smallest_i;

	// we receive a vector with their own curr index and the one one they are
	// paired with inside the vector.
	// ex. 
	// value: 1 8 4 5 9 2 6 3
	// index: 0 1 2 3 4 5 6 7
	// pair.: 1 0 3 2 5 4 7 6
	// the previous pair and index hold the position of the elements vector in
	// the past recursion, the one we extracted the winners from

	// here we extract the winners and update their current index and pair
	// (in the newly made vector from below) and point the prev to elements current
	for (int i = 0, index = 0; i < elements.size(); i++, i++, index++)
	{
		if (i == elements.size())
			break ;

		
	}

	const std::

}

std::vector<element> mergeInsertionSort(const std::vector<element>& elements)
{
	std::vector<element> biggestFromElements;
	element biggest, smallest;
	int biggest_i, smallest_i;

	// value	 : 5 3 8 4 1 9 2 6 8 3 7
	// prev_pair : 
	// prev_my.  :
	// curr_my   : 0 1 2 3 4 5 6 7 8 9 10
	// curr_pair : 1 0 3 2 5 4 7 6 9 8 

	for (int i = 0, index = 0; i < elements.size(); i++, i++, index++)
	{
		if (i == elements.size())
			break ;

		biggest_i = elements[i] > elements[i+1] ? i : i+1;
		smallest_i = elements[i] < elements[i+1] ? i : i+1;

		biggest.value = elements[biggest_i].value;
		biggest.prev = elements[biggest_i].curr;
		biggest.curr.my_index = index;
		biggest.curr.pair_index = smallest_i;
	}

	// value.    : 5 8 9 6 8
	// prev_my.  : 0 2 5 7 8
	// prev_pair : 1 3 4 6 9
	// curr_my   : 0 1 2 3 4
	// curr_pair : 1 0 3 2 

	const std::vector<element> sorted = mergeInsertionSort(biggestFromElements);
	std::vector<element> copy = sorted;
	for (element e : copy)
	{
		int prev_index = elements[e.prev].my_index;
		e.prev = elements[e.prev.my_index].prev;
		e.curr = e.prev;
	}

	// 8 9
	// 1 2
	// 0 3
	// 0 1
	// 1 0

	// sort


	// the sorted has the current pairs, so before everything happens we update the
	// newly copied one to point to the old pairs. then we insert using the 
	std::vector<element> insertToSorted = sorted;
	for (int i = 0; i < sorted.size(); i++)
	{
		element curr_element& = ;
		int pair_index = sorted[i].curr.pair_index;
		int prev_pair_index = sorted[i].prev.pair_index;
		insertToSorted[i].curr = inser

		std::vector<element>::iterator pos = std::lower_bound(insertToSorted.begin(), insertToSorted.end(), elements[pair_index]);
		// inserted the current loser pair, which already has the right previous pair
		// need to change the current pain index to prev pair index
		insertToSorted






		// im not sure if its supposed to be previous or current
		// insertEement(insertToSorted, elements[sorted[i].prev.pair_index]);
		std::vector<element>::iterator it = std::lower_bound(insertToSorted.begin(), insertToSorted.end(), elements[sorted[i].prev.pair_index]);
		insertToSorted.insert(it, elements[sorted[i].prev.pair_index]);
		(*it).curr = sorted[]
	}

	// 8 9 8



}



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
		FordJohnsonVector();
		sortDeque();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	}

}