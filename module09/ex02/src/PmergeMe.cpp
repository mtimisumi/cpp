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
	_vec.push_back({value, NULL, NULL});
	_deq.push_back({value, NULL, NULL});
}

void PmergeMe::FordJohnson()
{
	size_t elementCount = _vec.size();
	int vecComp;
	int deqComp;

	printContainer(_vec, "Before:\t");

	std::chrono::high_resolution_clock::time_point vStart = std::chrono::high_resolution_clock::now();
	_vec = mergeInsertionSort(_vec);
	std::chrono::high_resolution_clock::time_point vEnd = std::chrono::high_resolution_clock::now();
	double _vecUs = std::chrono::duration<double, std::micro>(vEnd - vStart).count();

	vecComp = comparisons;
	comparisons = 0;

	std::chrono::high_resolution_clock::time_point dStart = std::chrono::high_resolution_clock::now();
	_deq = mergeInsertionSort(_deq);
	std::chrono::high_resolution_clock::time_point dEnd = std::chrono::high_resolution_clock::now();
	double _deqUs = std::chrono::duration<double, std::micro>(dEnd - dStart).count();

	deqComp = comparisons;

	printContainer(_vec, "After:\t");

	std::cout << "Time to process range of " << elementCount << " elements with std::vector: " << _vecUs << " us\n";
	std::cout << "Time to process range of " << elementCount << " elements with std::deque: " << _deqUs << " us\n";

	std::cout << "Comparisons for sorting the vector: " << vecComp << "\n";
	std::cout << "Comparisons for sorting the deque: " << deqComp << "\n";
}


// void PmergeMe::FordJohnson()
// {
// 	size_t elementCount = _vec.size();

// 	printContainer(_vec, "Before:\t");

// 	int comparisons = 0;
// 	std::chrono::high_resolution_clock::time_point vStart = std::chrono::high_resolution_clock::now();
// 	_vec = mergeInsertionSort(_vec);
// 	std::chrono::high_resolution_clock::time_point vEnd = std::chrono::high_resolution_clock::now();
// 	double _vecUs = std::chrono::duration<double, std::micro>(vEnd - vStart).count();
	
// 	std::chrono::high_resolution_clock::time_point dStart = std::chrono::high_resolution_clock::now();
// 	_deq = mergeInsertionSort(_deq);
// 	std::chrono::high_resolution_clock::time_point dEnd = std::chrono::high_resolution_clock::now();
// 	double _deqUs = std::chrono::duration<double, std::micro>(dEnd - dStart).count();

// 	printContainer(_vec, "After:\t");

// 	std::cout << "Time to process range of " << elementCount << " elements with std::vector: " << _vecUs << " us\n";
// 	std::cout << "Time to process range of " << elementCount << " elements with std::deque: " << _deqUs << " us\n";

// }

bool element::operator>(const element& other) const
{
	return value > other.value;
}

bool element::operator<=(const element& other) const
{
	return value <= other.value;
}

bool element::operator>=(const element& other) const
{
	return value >= other.value;
}
