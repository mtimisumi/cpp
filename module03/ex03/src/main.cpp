#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	kiara("Kiara");
	DiamondTrap	ella("Ella");

	ella.showStats();
	kiara.showStats();

	ella.attack("Kiara");
	kiara.takeDamage(30);
	kiara.guardGate();
	kiara.beRepaired(200);
	ella.highFivesGuys();
	kiara.highFivesGuys();
	ella.whoAmI();
	kiara.whoAmI();

	ella.showStats();
	kiara.showStats();
	
}