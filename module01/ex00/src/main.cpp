#include "Zombie.hpp"

int	main()
{
	Zombie	*zombie;

	zombie = newZombie("Joan");
	zombie->announce();
	delete zombie;
	randomChump("Mary");
}