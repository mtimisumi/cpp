#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	_brain = new Brain;
	_brain->haveIdeas("cat ideas");
	if (debugEnable)
		std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& other)
{
	*this = other;
	if (debugEnable)
		std::cout << "Cat copy constructor called\n";
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other) {
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	if (debugEnable)
		std::cout << "Cat copy assignment operator called\n";
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	if (debugEnable)
		std::cout << "Cat destructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << "Meow\n";
}

const std::string& Cat::getIdea() const
{
	return _brain->getIdea();
}
