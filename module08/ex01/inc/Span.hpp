#pragma once
#include <iostream>
#include <set>
#include <limits>
#include <iterator>
#include <algorithm>

class Span
{
	private:
		unsigned int 		_size;
		std::multiset<int>	_set;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int n);
		long shortestSpan()const;
		long longestSpan() const;

		template<typename T_iterator>
		void addNumbers(T_iterator begin, T_iterator end)
		{
			std::for_each(begin, end, [this](int n) {addNumber(n); });
		}

	private:
		class NoMoreSpaceException : public std::exception
		{
			const char* what() const noexcept override;
		};
		class NotEnoughNumbersException : public std::exception
		{
			const char* what() const noexcept override;
		};

};