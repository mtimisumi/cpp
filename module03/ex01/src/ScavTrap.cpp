#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :  ClapTrap()
{
	std::cout << CYAN << "ScavTrap " << _name << " default constructor called\n" << RESET;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << CYAN << "ScavTrap " << _name << " constructor called\n" << RESET;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << MAGENTA << "ScavTrap " << _name << " destructor called\n" << RESET;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << CYAN << "ScavTrap " << _name << " copy constructor called\n" << RESET;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << BLUE << "ScavTrap " << _name << " copy assignment operator called\n" << RESET;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (!hasHitPoints("attack") || !hasEnergyPoints("attack")) {
		return ;
	}
	std::cout << YELLOW << "ScavTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!\n" << RESET;
	_energyPoints -= 1;
}

void	ScavTrap::guardGate()
{
	if (!hasHitPoints("guard gate.")) {
		return ;
	}
	std::cout << YELLOW << _name << " is now in Gate keeping mode.\n" << RESET;
}