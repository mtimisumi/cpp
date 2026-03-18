#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called\n";
	_type = "Cat";
}

Cat::Cat(const Cat& other)
{
	*this = other;
	std::cout << "Cat copy constructor called\n";
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "Cat copy assignment operator called\n";
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << "Meow\n";
}
