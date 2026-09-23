#include "PmergeMe.hpp"

int comparisons = 0;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
: _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}

	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::addNumber(int value)
{
	if (_vec.size() == 5462)
		throw std::length_error("number amount cannot exceed 5462");

	_vec.push_back({value, NULL, NULL});
	_deq.push_back({value, NULL, NULL});
}

void PmergeMe::FordJohnson()
{
	comparisons = 0;
	size_t elementCount = _vec.size();

	printContainer(_vec, "\nBefore:\t");

	std::chrono::high_resolution_clock::time_point vStart = std::chrono::high_resolution_clock::now();
	_vec = mergeInsertionSort(_vec);
	std::chrono::high_resolution_clock::time_point vEnd = std::chrono::high_resolution_clock::now();
	double _vecUs = std::chrono::duration<double, std::micro>(vEnd - vStart).count();

	std::chrono::high_resolution_clock::time_point dStart = std::chrono::high_resolution_clock::now();
	_deq = mergeInsertionSort(_deq);
	std::chrono::high_resolution_clock::time_point dEnd = std::chrono::high_resolution_clock::now();
	double _deqUs = std::chrono::duration<double, std::micro>(dEnd - dStart).count();

	printContainer(_vec, "After:\t");

	std::cout << "Time to process range of " << elementCount << " elements with std::vector: " << _vecUs << " us\n";
	std::cout << "Time to process range of " << elementCount << " elements with std::deque: " << _deqUs << " us\n\n";

	validateContainer();
}

bool element::operator>(const element& other) const
{
	return value > other.value;
}

bool element::operator<(const element& other) const
{
	return value < other.value;
}

bool element::operator>=(const element& other) const
{
	return value >= other.value;
}

bool element::operator<=(const element& other) const
{
	return value <= other.value;
}

std::ostream& operator<<(std::ostream& os, const element& e)
{
	return os << e.value;
}

void PmergeMe::putContainer(std::vector<int>& v)
{
	if (v.size() > 5462)
		throw std::length_error("number amount cannot exceed 5462");

	_vec.clear();
	_deq.clear();

	for (size_t i = 0; i < v.size(); i++)
		this->addNumber(v[i]);
}

const char* const GREEN = "\033[32m";
const char* const RED = "\033[31m";
const char* const RESET = "\033[0m";

void PmergeMe::validateContainer()
{
	const bool sorted = isSorted(_vec);
	const int myComparisons = comparisons/2;
	const int maxComparisons = getMaxComparisons(_vec.size());

	std::cout << "Container is " << (sorted ? GREEN : RED) << (sorted ? "sorted" : "unsorted") << RESET;
	std::cout << " with " << (myComparisons <= maxComparisons ? GREEN : RED) << myComparisons << RESET << " comparisons, ";
	std::cout << "max amount of comparisons " << RED << maxComparisons << RESET << "\n\n";
}
