#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	emi("Emi");
	ClapTrap	kim("Kim");
	ClapTrap	copy(emi);

	copy = kim;

	emi.showStats();
	kim.showStats();

	emi.attack("Kim");
	kim.takeDamage(9);
	kim.showStats();
	kim.beRepaired(5);
	kim.showStats();
	kim.attack("Emi");
	emi.takeDamage(16);
	emi.showStats();
	emi.beRepaired(6);
	emi.attack("Kim");
	for (int i = 0; i < 10; i++) {
		kim.beRepaired(10);
	}
	kim.attack("someone");
	kim.showStats();

}