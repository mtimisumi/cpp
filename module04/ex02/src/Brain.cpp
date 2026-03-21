#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "Empty idea";
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "Brain copy constructor called\n";
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain copy assignment operator called\n";
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

void	Brain::setIdea(const std::string& idea)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = idea;
}

const std::string& Brain::getIdea() const
{
	return *_ideas;
}