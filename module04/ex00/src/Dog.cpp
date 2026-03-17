#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
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

void	Dog::makeSound()
{
	std::cout << "Woof...\n";
}