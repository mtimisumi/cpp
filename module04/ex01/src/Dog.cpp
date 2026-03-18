#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	_brain = new Brain;
	_brain->haveIdeas("dog ideas");
	if (debug)
		std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& other)
{
	*this = other;
	if (debug)
		std::cout << "Dog copy constructor called\n";
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other) {
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	if (debug)
		std::cout << "Dog copy assignment operator called\n";
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	if (debug)
		std::cout << "Dog destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << "Woof\n";
}

const std::string&	Dog::getIdea() const
{
	return _brain->getIdea();
}
