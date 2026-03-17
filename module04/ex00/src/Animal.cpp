#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

Animal::Animal(const std::string& type) : _type(type)
{
	std::cout << "Animal construcotr called\n";
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "Animal copy constructor called\n";
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "Animal copy assingment operator called\n";
	return (*this);
}

void	Animal::makeSound()
{
	std::cout << "Animal sounds...\n";
}