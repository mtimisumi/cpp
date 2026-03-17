#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	ichiro("Ichiro");
	ScavTrap	david("David");

	ichiro.attack("David");
	david.takeDamage(20);
	david.beRepaired(30);
	david.attack("Ichiro");
	ichiro.takeDamage(20);
	ichiro.guardGate();
	for (int i = 0; i < 6; i++) {
		david.takeDamage(20);
	}
	david.guardGate();
	david.beRepaired(10);

}