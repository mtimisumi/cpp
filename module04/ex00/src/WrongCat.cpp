#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called\n";
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other)
{
	*this = other;
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "WrongCat copy assignment operator called\n";
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong meow\n";
}
