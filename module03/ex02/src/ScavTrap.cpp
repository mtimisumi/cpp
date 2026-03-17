#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :  ClapTrap()
{
	std::cout << BLACK << "ScavTrap default constructor called\n" << RESET;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << BLACK << "ScavTrap " << _name << " destructor called\n" << RESET;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << BLACK << "ScavTrap " << _name << " constructor called\n" << RESET;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << BLACK << "ScavTrap " << _name << " copy constructor called\n" << RESET;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << BLACK << "ScavTrap " << _name << " copy assignment operator called\n" << RESET;
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