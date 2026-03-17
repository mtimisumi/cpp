#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define RESET "\033[0m"
# define BLACK "\033[30m"

class	ClapTrap
{
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap&	operator=(const ClapTrap& other);

	public:
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		bool	hasHitPoints(const std::string& action);
		bool	hasEnergyPoints(const std::string& action);

	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif