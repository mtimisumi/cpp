#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{}

PmergeMe::~PmergeMe()
{}

void PmergeMe::addNumber(int value, int index)
{
	_vec.push_back({value, index});
	_deq.push_back({value, index});
}

size_t PmergeMe::getSizeVec() const
{
	return _vec.size();
}

size_t PmergeMe::getSizeDeq() const
{
	return _deq.size();
}

s PmergeMe::getVec(int index) const
{
	return _vec[index];
}

s PmergeMe::getDeq(int index) const
{
	return _deq[index];
}

bool s::operator>(const s& other) const
{
	return value > other.value;
}

bool s::operator<(const s& other) const
{
	return value < other.value;
}