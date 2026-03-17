#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	bento("Bento");
	FragTrap	puma("Puma");

	bento.showStats();
	puma.showStats();
	puma.attack("Bento");
	bento.takeDamage(30);
	bento.showStats();
	bento.attack("Puma");
	puma.takeDamage(100);
	puma.showStats();
	bento.highFivesGuys();
	bento.showStats();
	puma.highFivesGuys();
	puma.showStats();
}