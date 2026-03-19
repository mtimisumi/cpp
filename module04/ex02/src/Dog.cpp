#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called\n";
	_type = "Dog";
}

Dog::Dog(const Dog& other)
{
	*this = other;
	std::cout << "Dog copy constructor called\n";
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "Dog copy assignment operator called\n";
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << "Woof\n";
}
