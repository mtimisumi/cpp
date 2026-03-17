#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	ichiro("Ichiro");
	ScavTrap	david("David");
	ScavTrap	copy(ichiro);

	copy = david;

	ichiro.showStats();
	david.showStats();
	ichiro.attack("David");
	david.takeDamage(20);
	david.showStats();
	david.beRepaired(30);
	david.showStats();
	david.attack("Ichiro");
	ichiro.takeDamage(20);
	ichiro.showStats();
	ichiro.guardGate();
	ichiro.showStats();
	for (int i = 0; i < 6; i++) {
		david.takeDamage(20);
	}
	david.guardGate();
	david.showStats();
	david.beRepaired(10);
}