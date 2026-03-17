#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	_name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called\n";
}

ClapTrap::ClapTrap(const std::string& name) :
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap " << _name << " copy constructor called\n";
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout<< "ClapTrap " << _name << " copy asignment operator called\n";
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!hasHitPoints("attack.") || !hasEnergyPoints("attack.")) {
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!\n";
	_energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!hasHitPoints("take damage.")) {
		return ;
	}
	std::cout << _name << " gets attacked, losing " << amount
			  << " hit points!\n";
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!hasHitPoints("repair.") || !hasEnergyPoints("repair.")) {
		return ;
	}
	std::cout << _name << " repairs itself, regaining "
			  << amount << " hit points!\n";
	_hitPoints += amount;
	_energyPoints -= 1;
}

bool	ClapTrap::hasHitPoints(const std::string& action)
{
	if (_hitPoints < 1) {
		std::cout << _name << " is already dead and cannot do action: "
				  << action << std::endl;
		return false;
	}
	return true;
}

bool	ClapTrap::hasEnergyPoints(const std::string& action)
{
	if (_energyPoints < 1) {
		std::cout << _name << " has no energypoints left for action: "
				  << action << std::endl;
		return false;
	}
	return true;
}

