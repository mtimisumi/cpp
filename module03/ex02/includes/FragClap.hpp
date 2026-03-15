#ifndef FRAGCLAP_HPP
# define FRAGCLAP_HPP

# include "ClapTrap.hpp"

class	FragClap : public ClapTrap
{
	public:
		FragClap();
		~FragClap();
		FragClap(const std::string& name);
		FragClap(const FragClap& other);
		FragClap&	operator=(const FragClap& other);

	public:
		void	highFivesGuys();

};

#endif