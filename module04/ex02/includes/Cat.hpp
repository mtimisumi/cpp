#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat() override;

	public:
		void makeSound() const override;
		void haveIdea(const std::string& idea);
		const std::string& getIdea() const;

	private:
		Brain*	_brain;
};

#endif