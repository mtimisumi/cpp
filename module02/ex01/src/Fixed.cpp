#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";

	_rawBits = other._rawBits;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "copy assignment operator called\n";

	if (this != &other)
		_rawBits = other._rawBits;
	return (*this);
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";

	_rawBits = value << FRACTBITS;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";

	_rawBits = roundf(value * (float)(1 << FRACTBITS));
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";

	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";

	_rawBits = raw;
}

int	Fixed::toInt(void) const
{
	return (_rawBits >> FRACTBITS);
}

float	Fixed::toFloat(void) const
{
	return ((float)_rawBits / (float)(1 << FRACTBITS));
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fx)
{
	os << fx.toFloat();
	return os;
}
