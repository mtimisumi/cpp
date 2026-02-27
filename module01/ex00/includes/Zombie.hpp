#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	public:
	void	announce(void);
	void	setName(const std::string& name);

	private:
		std::string	m_name;
};

#endif