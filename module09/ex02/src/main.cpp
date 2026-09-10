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
	std::vector<s> v;

	for (int i = 0; i < p.getSizeVec(); i++, i++)
	{
		if (i == p.getSizeVec())
			break ;

		struct s biggest = (p.getVec(i) > p.getVec(i+1)) ? p.getVec(i) : p.getVec(i+1);
		struct s smallest = (p.getVec(i) < p.getVec(i+1)) ? p.getVec(i) : p.getVec(i+1);
		biggest.pair_index = smallest.index;
		smallest.pair_index = biggest.index;
		v.push_back(biggest);
	}

	std::vector<s> sorted = sortVector(v);
}

// std::vector<s> sortVector(const std::vector<s>& v)
// {
// 	// 4 2 3 6 5 1 7 9
// 	// 0 1 2 3 4 5 6 7
// 	std::vector<s> biggestFromPairs;

// 	for (int i = 0; i < v.size(); i++, i++)
// 	{
// 		if (i == v.size())
// 			break ;

// 		struct s biggest, smallest;
// 		if (v[i] > v[i+1])
// 		{
// 			biggest = v[i];
// 			smallest = v[i+1];
// 			biggest.index = i;
// 			smallest.index = i+1;
// 			biggest.pair_index = i+1;
// 			smallest.pair_index = i;

// 		}
// 		else
// 		{
// 			biggest = v[i+1];
// 			smallest = v[i];
// 			biggest.index = i+1;
// 			smallest.index = i;
// 			biggest.pair_index = i;
// 			smallest.pair_index = i+1;
// 		}

// 		biggestFromPairs.push_back(biggest);
// 	}
// 	// 4 6 5 9
// 	// 0 1 2 3
// 	// 


// 	std::vector<s> sorted = sortVector(biggestFromPairs);

// 	// 4 5 6 9
// 	// 0 2 1 3
// 	// 

// 	for (size_t i = 0, index = 1; i < sorted.size(); i++, index++)
// 	{
		
// 	}
// }


void sortDeque(PmergeMe& p)
{

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