#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	_rawBits = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(int const value)
{
	_rawBits = value << 8;
}

Fixed::Fixed(float const value)
{
	
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	_rawBits = other.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "copy assignment operator called\n";
	if (this != &other)
		_rawBits = other.getRawBits();
	return (*this);
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