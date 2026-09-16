#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <iterator>

struct element
{
	int				value;
	const element*	pair;
	const element*	prev;

	bool operator>(const element& other) const;
	bool operator<=(const element& other) const;
};


class PmergeMe
{
	private:
		std::vector<element> _vec;
		std::deque<element> _deq;

		double _vecUs;
		double _deqUs;

		// int _vecComp;
		// int _deqComp;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void addNumber(int value);
		size_t getSizeVec() const;
		size_t getSizeDeq() const;
		element getVec(int index) const;
		element getDeq(int index) const;

		void FordJohnson();
};

template<typename Container> Container JacobsthalSort(const Container& example, const Container& elements);
template<typename Container> Container mergeInsertionSort(Container& elements);
template<typename Container> Container getBiggestFromElements(const Container& elements, element& saved);
template<typename Container> void insertElement(Container& insertToSorted, element toInsert);
template<typename Container> bool startSorting(Container& elements);
template<typename Container> void printContainer(Container& c, const std::string& msg);
template<typename Container> void binaryInsert(Container& c, element& e, int index);


#include "PmergeMe.tpp"