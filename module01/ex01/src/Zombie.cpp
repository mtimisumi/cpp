#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << _name << ": Destroying zombie" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string& name)
{
	_name = name;
}
