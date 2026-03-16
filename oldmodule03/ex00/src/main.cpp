#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	emi("Emi");
	ClapTrap	kim("Kim");

	emi.attack("Kim");
	kim.takeDamage(9);
	kim.beRepaired(5);
	kim.attack("Emi");
	emi.takeDamage(16);
	emi.beRepaired(6);
	emi.attack("Kim");
}