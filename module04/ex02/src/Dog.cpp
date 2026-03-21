#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	_brain = new Brain;
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& other)
{
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called\n";
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other) {
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << "Dog copy assignment operator called\n";
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << "Woof\n";
}

void	Dog::haveIdea(const std::string& idea)
{
	_brain->setIdea(idea);
}

const std::string&	Dog::getIdea() const
{
	return _brain->getIdea();
}
