#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
		_vec = other._vec;

	return *this;
}

PmergeMe::~PmergeMe()
{}

void PmergeMe::addNumber(int value)
{
	_vec.push_back({value, -1, NULL});
	_deq.push_back({value, -1, NULL});
}

size_t PmergeMe::getSizeVec() const
{
	return _vec.size();
}

size_t PmergeMe::getSizeDeq() const
{
	return _deq.size();
}

void PmergeMe::FordJohnsonVector()
{
	std::cout << "original: \n";
	for (element e : _vec)
	{
		std::cout << e.value << " ";
	}
	std::cout << "\n\n";

	std::vector<element> biggestFromElements = getBiggestFromElements(_vec);
	// printing...
	// printBiggestFromElements(biggestFromElements);
	const std::vector<element> sorted = mergeInsertionSort(biggestFromElements);
	std::vector<element> insertToSorted = sorted;

	for (element e : sorted)
	{
		element toInsert = _vec[e.pair_index];
		insertElement(insertToSorted, toInsert);
	}

	for (element e : insertToSorted)
	{
		std::cout << e.value << " ";
	}
	std::cout << "\n";
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

bool element::operator<(const element& other) const
{
	return value < other.value;
}

