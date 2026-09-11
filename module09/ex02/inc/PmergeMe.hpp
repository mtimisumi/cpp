#pragma once

#include <vector>
#include <deque>

struct pair
{
	int my_index;
	int pair_index;
};

struct element
{
	int value;
	pair prev;
	pair curr;

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

		void addNumber(int value, int index);
		size_t getSizeVec() const;
		size_t getSizeDeq() const;
		element getVec(int index) const;
		element getDeq(int index) const;

		void FordJohnsonVector();

};

std::vector<element> mergeInsertionSort(const std::vector<element>& elements);