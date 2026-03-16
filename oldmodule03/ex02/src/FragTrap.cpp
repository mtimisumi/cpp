#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap " << _name << " default constructor called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructor called\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name << " constructor called\n";

	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " copy constructor called\n";
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap " << _name << " copy assignment operator called\n";

	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (_hitPoints < 1) {
		std::cout << _name << " is dead and cannot attack.\n";
		return ;
	}
	if (_energyPoints < 1) {
		std::cout << _name << " has no energypoints left to attack.\n";
		return ;
	}
	std::cout << "FragTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!\n";
	_energyPoints -= 1;
}

void	FragTrap::highFivesGuys()
{
	if (_hitPoints < 1) {
		std::cout << _name << " is dead and cannot high five.\n";
		return ;
	}
	if (_energy)
	std::cout << _name << " reguesting to positively highfive.\n";
}

