#include "ScavTrap.hpp"
#include "FragClap.hpp"

int	main()
{
	FragClap	bento("Bento");
	ClapTrap	bink("Binkie");
	ScavTrap	puma("Puma");

	bento.attack("Binkie");
	bink.takeDamage(30);
	bink.beRepaired(30);
	bento.attack("puma");
	puma.takeDamage(30);
	puma.guardGate();
	bink.attack("Bento");
	puma.attack("Bento");
	bento.highFivesGuys();
}