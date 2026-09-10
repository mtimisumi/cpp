#pragma once

#include <vector>
#include <deque>

struct s
{
	int value;
	int index;
	int pair_index;

	bool operator>(const s& other) const;
	bool operator<(const s& other) const;
};



class PmergeMe
{
	private:
		std::vector<s> _vec;
		std::deque<s> _deq;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void addNumber(int value, int index);
		size_t getSizeVec() const;
		size_t getSizeDeq() const;
		s getVec(int index) const;
		s getDeq(int index) const;

};