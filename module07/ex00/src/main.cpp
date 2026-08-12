#include "whatever.hpp"
#include <iostream>

int main()
{
	int a = 2;
	int b = 3;

	std::cout << "min(2, 3): " << min(a, b) << "\n";
	std::cout << "max(2, 3): " << max(a, b) << "\n";

	double d = 2.2;
	double e = 2.23;

	std::cout << "min(2.2, 2.23): " << min(d, e) << "\n";
	std::cout << "max(2.2, 2.23): " << max(e, d) << "\n";

	char c = 'c';
	char f = 'f';

	std::cout << "original: c: " << c << ", f: " << f << "\n";
	swap(c, f);
	std::cout << "swapped : c: " << c << ", f: " << f << "\n";
}