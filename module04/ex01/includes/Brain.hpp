#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include "debugEnable.hpp"

class	Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

	public:
		void	haveIdeas(const std::string& ideas);
		const std::string&	getIdea() const;

	private:
		std::string	_ideas[100];
};

#endif