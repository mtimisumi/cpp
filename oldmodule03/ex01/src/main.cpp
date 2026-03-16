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
}