#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	Weapon club = Weapon("crude spiked club");
	Weapon knife = Weapon("knife");

	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some type of other club");
	bob.attack();
	std::cout << std::endl;

	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(club);
	jim.attack();
	club.setType("crude spiked club");
	jim.attack();
	jim.setWeapon(knife);
	jim.attack();
}