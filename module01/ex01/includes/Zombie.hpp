#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	public:
		Zombie();
		~Zombie();
		Zombie(const std::string& name);

	public:
		void	announce(void);
		void	setName(const std::string& name);

	private:
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif