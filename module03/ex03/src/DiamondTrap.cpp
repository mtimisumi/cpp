#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap(), ScavTrap(), FragTrap(), _name("default")
{
	std::cout << BLACK << "DiamondTrap default constructor called\n" << RESET;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BLACK << "DiamondTrap " << _name << " destructor called\n" << RESET;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << BLACK << "DiamondTrap " << _name << " constructor called\n" << RESET;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << BLACK << "DiamondTrap " << _name << " copy constructor called\n" << RESET;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << BLACK << "DiamondTrap " << _name << " copy assignment operator called\n" << RESET;
	if (this != &other) {
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "WhoAmI DiamondTrap: " << _name << std::endl;
	std::cout << "WhoAmI ClapTrap: " << ClapTrap::_name << std::endl;
}


void	DiamondTrap::showStats() const
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

