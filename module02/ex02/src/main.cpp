#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f)*Fixed(2));

	std::cout << "value a: " << a << std::endl;
	std::cout << "a pre increment: " <<  ++a << std::endl;
	std::cout << "value a:" << a << std::endl;
	std::cout << "a post increment: " << a++ << std::endl;
	std::cout << "value a: " << a << std::endl;
	std::cout << "value b: " << b << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a,b) << std::endl;
	return 0;
}