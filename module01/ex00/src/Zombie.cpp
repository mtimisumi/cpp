#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << m_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string& name)
{
	m_name = name;
}