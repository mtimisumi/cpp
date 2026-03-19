#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	Animal *a = new Dog;
	a->makeSound();
	delete a;

	Animal b;
	b.makeSound();

	Animal *c = new Animal;
	c->makeSound();
}
