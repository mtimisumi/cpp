#include "Span.hpp"
#include <vector>

int main()
{
	Span a(5);
	a.addNumber(1);
	a.addNumber(4);
	a.addNumber(5);
	a.addNumber(8);

	// between 4 and 5
	std::cout << a.shortestSpan() << "\n";
	// between 8 and 1
	std::cout << a.longestSpan() << "\n";

	a.addNumber(5);
	// between 5 and 5
	std::cout << a.shortestSpan() << "\n";

	try
	{
		a.addNumber(17);
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}
	std::cout << "\n";

	Span b;
	try
	{
		b.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}
		try
	{
		b.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << "\n\n";
	}

	Span c(2);
	c.addNumber(INT32_MAX);
	c.addNumber(INT32_MIN);

	std::cout << c.shortestSpan() << "\n";
	std::cout << c.longestSpan() << "\n";
	// diff between int_min and int_max
	std::cout << (long)INT32_MAX - (long)INT32_MIN << "\n\n";


	std::vector<int> vec;
	for (int i = 0; i < 10000; i++)
	{
		vec.push_back(i);
	}

	// adding numbers through a container
	Span d(10000);
	d.addNumbers(vec.begin(), vec.end());

	// should be 1
	std::cout << d.shortestSpan() << "\n";
	// between 0 and 9999
	std::cout << d.longestSpan() << "\n";
}