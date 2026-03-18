#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "Empty idea";
	if (debug)
		std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& other)
{
	*this = other;
	if (debug)
		std::cout << "Brain copy constructor called\n";
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	if (debug)
		std::cout << "Brain copy assignment operator called\n";
	return *this;
}

Brain::~Brain()
{
	if (debug)
		std::cout << "Brain destructor called\n";
}

void	Brain::haveIdeas(const std::string& ideas)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = ideas;
}

const std::string& Brain::getIdea() const
{
	return *_ideas;
}