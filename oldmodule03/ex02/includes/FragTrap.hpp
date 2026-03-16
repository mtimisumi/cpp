#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FrapTrap();
		~FrapTrap();
		FrapTrap(const std::string& name);
		FrapTrap(const FrapTrap& other);
		FrapTrap&	operator=(const FrapTrap& other);

	public:
		void	attack(const std::stirng& target) override;
		void	highFivesGuys();

};

#endif