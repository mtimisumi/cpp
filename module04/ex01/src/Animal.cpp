#include "Animal.hpp"

Animal::Animal() : _type("animal")
{
	if (debugEnable)
		std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& other)
{
	*this = other;
	if (debugEnable)
		std::cout << "Animal copy constructor called\n";
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other) {
		_type = other._type;
	}
	if (debugEnable)
		std::cout << "Animal copy assingment operator called\n";
	return (*this);
}

Animal::~Animal()
{
	if (debugEnable)
		std::cout << "Animal destructor called\n";
}

void	Animal::makeSound() const
{
	if (debugEnable)
		std::cout << "Animal sounds\n";
}

const std::string&	Animal::getType() const
{
	return _type;
}