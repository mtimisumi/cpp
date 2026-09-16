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

size_t PmergeMe::getSizeVec() const
{
	return _vec.size();
}

size_t PmergeMe::getSizeDeq() const
{
	return _deq.size();
}

void PmergeMe::FordJohnson()
{
	printContainer(_vec, "unsorted numbers");

	_vec = mergeInsertionSort(_vec);
	_deq = mergeInsertionSort(_deq);

	printContainer(_vec, "sorted vector");
	printContainer(_deq, "sorted deque");
}

element PmergeMe::getVec(int index) const
{
	return _vec[index];
}

element PmergeMe::getDeq(int index) const
{
	return _deq[index];
}

bool element::operator>(const element& other) const
{
	return value > other.value;
}

bool element::operator<=(const element& other) const
{
	return value <= other.value;
}