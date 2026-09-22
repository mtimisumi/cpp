#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <utility>
#include <string>
#include <cstdlib>

extern int comparisons;

struct element
{
	int		value;
	element	*pair;
	element	*prev;

	bool operator>(const element& other) const;
	bool operator<(const element& other) const;
	bool operator>=(const element& other) const;
	bool operator<=(const element& other) const;
};

std::ostream& operator<<(std::ostream& os, const element& e);


class PmergeMe
{
	private:
		std::vector<element> _vec;
		std::deque<element> _deq;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void addNumber(int value);
		void FordJohnson();
		void putContainer(std::vector<int>& v);
		void validateContainer();
};

template<typename Container> int binaryInsert(Container& c, element& e, int index);
template<typename Container> Container JacobSthalSort(Container& c, element& saved);
template<typename Container> Container mergeInsertionSort(Container& elements);
template<typename Container> Container getBiggestFromElements(Container& elements, element& saved);
template<typename Container> bool startSorting(Container& elements, element& saved);
template<typename IndexContainer> void updateCIndex(IndexContainer& cShift, int pairIndex);
template<typename Container> void printContainer(Container& c, const std::string& msg);
template<typename Container> bool isSorted(Container& c);
int getMaxComparisons(int nbCount);

#include "PmergeMe.tpp"
