#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	bento("Bento");
	FragTrap	puma("Puma");

	puma.attack("Bento");
	bento.takeDamage(20);
	bento.attack("Puma");
	puma.takeDamage(100);
	bento.highFivesGuys();
	puma.highFivesGuys();
}