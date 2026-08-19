#include "Span.hpp"

Span::Span() : _size(0)
{}

Span::Span(unsigned int N) : _size(N)
{}

Span::Span(const Span& other) : _size(other._size)
{
	std::multiset<int>::iterator it;

	for (it = other._set.begin(); it != other._set.end(); ++it)
	{
		_set.insert(*it);
	}
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_set.clear();
		_size = other._size;

		std::multiset<int>::iterator it;
		for (it = other._set.begin(); it != other._set.end(); ++it)
			_set.insert(*it);
	}

	return *this;
}

Span::~Span()
{}

void Span::addNumber(int n)
{
	if (_set.size() == _size)
		throw NoMoreSpaceException();

	_set.insert(n);
}

long Span::shortestSpan()const
{
	if (_set.size() == 0 || _set.size() == 1)
		throw NotEnoughNumbersException();

	std::multiset<int>::iterator prev = _set.begin();
	std::multiset<int>::iterator it;
	long shortest INT64_MAX;

	for (it = ++_set.begin(); it != _set.end(); ++it)
	{
		long diff = (long)*it - (long)*prev;
		if (diff < shortest)
			shortest = diff;
		prev = it;
	}

	return shortest;
}

long Span::longestSpan() const
{
	if (_set.size() == 0 || _set.size() == 1)
		throw NotEnoughNumbersException();

	return ((long)*_set.rbegin() - (long)*_set.begin());
}

const char* Span::NoMoreSpaceException::what() const noexcept
{
	return "No more space";
}

const char* Span::NotEnoughNumbersException::what() const noexcept
{
	return "Not enough numbers to compare";
}