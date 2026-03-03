#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name)
{}

void	HumanB::attack()
{
	std::cout << _name << " attacks with their ";
	if (_weapon)
		std::cout << _weapon->getType() << std::endl;
	if (!_weapon)
		std::cout << "no weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}
