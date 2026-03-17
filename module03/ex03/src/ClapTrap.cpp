#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	_name("default_clap_trap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << BLACK << "ClapTrap default constructor called\n" << RESET;
}

ClapTrap::~ClapTrap()
{
	std::cout << BLACK << "ClapTrap " << _name << " destructor called\n" << RESET;
}

ClapTrap::ClapTrap(const std::string& name) :
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << BLACK << "ClapTrap " << _name << " constructor called\n" << RESET;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << BLACK << "ClapTrap " << _name << " copy constructor called\n" << RESET;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout<< BLACK << "ClapTrap " << _name << " copy asignment operator called\n" << RESET;
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

void	ClapTrap::showStats() const
{
	if (_name.length() > 10)
		std::string temp = _name.substr(0,8) + '.';
	else
		std::string temp = _name;

	std::cout << std::setw(10) << "Name:"
			  << std::setw(10) << "HP:"
			  << std::setw(10) << "EP:"
			  << std::setw(10) << "AD:" << std::endl
			  << std::setw(10) << _name
			  << std::setw(10) << _hitPoints
			  << std::setw(10) << _energyPoints
			  << std::setw(10) << _attackDamage
			  << std::endl << std::endl;
}

