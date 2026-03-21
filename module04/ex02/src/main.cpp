#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	// Animal b;
	// b.makeSound();

	// Animal *c = new Animal;
	// c->makeSound();

	Animal *a = new Dog;
	a->makeSound();
	Animal *b = new Cat;
	b->makeSound();

	delete a; delete b;

}
