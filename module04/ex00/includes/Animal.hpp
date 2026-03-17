#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	Animal
{
	public:
		Animal();
		~Animal();
		Animal(const std::string& type);
		Animal(const Animal& other);
		Animal&	operator=(const Animal& other);

	public:
		virtual void	makeSound();

	protected:
		std::string	_type;
};

#endif