#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Fixed default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Fixed destructor called\n";
}

Fixed::Fixed(int const value)
{
	std::cout << "Fixed int constructor called\n";
	_rawBits = value << FRACTBITS;
}

Fixed::Fixed(float const value)
{
	std::cout << "Fixed float constructor called\n";
	_rawBits = roundf(value * (1 << FRACTBITS));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Fixed copy constructor called\n";
	_rawBits = other._rawBits;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Fixed copy assignment operator called\n";
	if (this != &other)
		_rawBits = other._rawBits;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "Fixed getRawBits member function called\n";
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "Fixed setRawBits member function called\n";
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

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_rawBits > other._rawBits);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_rawBits < other._rawBits);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_rawBits >= other._rawBits);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_rawBits <= other._rawBits);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_rawBits == other._rawBits);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_rawBits != other._rawBits);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed&	Fixed::operator++()
{
	_rawBits += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	_rawBits += 1;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	_rawBits -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	_rawBits -= 1;
	return (temp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return ((a < b) ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return ((a > b) ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a < b) ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a > b) ? a : b);
}
