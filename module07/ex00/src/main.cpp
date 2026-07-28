#include "whatever.hpp"
#include <iostream>

int main()
{
	int a = 2;
	int b = 3;

	std::cout << min(a, b) << "\n";
	std::cout << max(a, b) << "\n";

	double d = 2.2;
	double e = 2.23;

	std::cout << min(d, e) << "\n";
	std::cout << max(e, d) << "\n";

	char c = 'c';
	char f = 'f';

	swap(c, f);
	std::cout << "c: " << c << ", f: " << f << "\n";
}