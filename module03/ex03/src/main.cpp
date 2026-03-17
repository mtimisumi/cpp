#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	kiara("Kiara");
	DiamondTrap	ella("Ella");
	DiamondTrap copy;

	copy = ella;

	ella.showStats();
	kiara.showStats();

	ella.attack("Kiara");
	kiara.takeDamage(30);
	kiara.showStats();
	kiara.guardGate();
	kiara.beRepaired(200);
	kiara.showStats();
	ella.highFivesGuys();
	kiara.highFivesGuys();

	ella.showStats();
	kiara.showStats();

	ella.whoAmI();
	kiara.whoAmI();
	
}