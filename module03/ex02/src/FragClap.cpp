#include "FragClap.hpp"

FragClap::FragClap() : ClapTrap()
{
	std::cout << "FragClap " << _name << " default constructor called\n";
}

FragClap::~FragClap()
{
	std::cout << "FragClap " << _name << " destructor called\n";
}

FragClap::FragClap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragClap " << _name << " constructor called\n";

	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragClap::FragClap(const FragClap& other) : ClapTrap(other)
{
	std::cout << "FragClap " << _name << " copy constructor called\n";
}

FragClap&	FragClap::operator=(const FragClap& other)
{
	std::cout << "FragClap " << _name << " copy assignment operator called\n";

	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

void	FragClap::highFivesGuys()
{
	std::cout << _name << " reguesting to positively highfive.\n";
}

