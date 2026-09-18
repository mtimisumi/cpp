#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

void PmergeMe::addNumber(int value)
{
	_vec.push_back({value, NULL, NULL});
	_deq.push_back({value, NULL, NULL});
}


void PmergeMe::FordJohnson()
{
	printContainer(_vec, "unsorted numbers");

	_vec = mergeInsertionSort(_vec);
	_deq = mergeInsertionSort(_deq);

	// printContainer(_vec, "1");
	printContainer(_vec, "sorted vector");
	printContainer(_deq, "sorted deque");
}

bool element::operator>(const element& other) const
{
	return value > other.value;
}

bool element::operator<=(const element& other) const
{
	return value <= other.value;
}
