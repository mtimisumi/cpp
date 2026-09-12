#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <iterator>

struct element
{
	int				value;
	int				pair_index;
	const element*	prev;

	bool operator>(const element& other) const;
	bool operator<(const element& other) const;
};


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
		size_t getSizeVec() const;
		size_t getSizeDeq() const;
		element getVec(int index) const;
		element getDeq(int index) const;

		void FordJohnsonVector();

};

template<typename Container> Container mergeInsertionSort(Container& elements);
template<typename Container> Container getBiggestFromElements(const Container& elements, element& saved);
template<typename Container> void insertElement(Container& insertToSorted, element toInsert);
template<typename Container> void printContainer(Container& c);
template<typename Container> bool startSorting(Container& elements);
// std::vector<element> mergeInsertionSort(std::vector<element>& elements);
// std::vector<element> getBiggestFromElements(const std::vector<element>& elements, element& saved);
// void insertElement(std::vector<element>& insertToSorted, element toInsert);

// void printValue(const std::vector<element>& ew);


#include "PmergeMe.tpp"