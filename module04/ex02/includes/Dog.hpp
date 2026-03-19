#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog() override;

	public:
		void makeSound() const override;
		const std::string& getIdea() const;

	private:
		Brain*	_brain;
};

#endif