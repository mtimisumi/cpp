#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :  ClapTrap()
{
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructor called\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << " constructor called\n";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " copy constructor called\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap " << _name << " copy assignment operator called\n";
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
	std::cout << "ScavTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!\n";
	_energyPoints -= 1;
}

void	ScavTrap::guardGate()
{
	if (!hasHitPoints("guard gate.") || !hasEnergyPoints("guard gate.")) {
		return ;
	}
	std::cout << _name << " is now in Gate keeping mode.\n";
	_energyPoints -= 1;
}