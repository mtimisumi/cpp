#pragma once

#include <vector>
#include <deque>
#include <iostream>

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

std::vector<element> mergeInsertionSort(const std::vector<element>& elements);
std::vector<element> getBiggestFromElements(const std::vector<element>& elements);
void insertElement(std::vector<element>& insertToSorted, element toInsert);
void printBiggestFromElements(const std::vector<element>& getBiggestFromElements);
