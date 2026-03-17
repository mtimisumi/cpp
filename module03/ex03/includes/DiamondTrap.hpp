#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iomanip>

class	DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap&	operator=(const DiamondTrap& other);
	
	public:
		void	whoAmI();
		void	showStats() const;
		using ScavTrap::attack;

	private:
		std::string	_name;

};

#endif