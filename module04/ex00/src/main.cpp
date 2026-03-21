#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

int	main()
{
	Animal *a = new Animal;
	Animal *c = new Cat;
	Animal *d = new Dog;

	std::cout << std::endl << "a type: " << a->getType() << std::endl;
	std::cout << "a sound: "; a->makeSound(); std::cout << std::endl;

	std::cout << "c type: " << c->getType() << std::endl;
	std::cout << "c sound: "; c->makeSound(); std::cout << std::endl;

	std::cout << "d type: " << d->getType() << std::endl;
	std::cout << "d sound: "; d->makeSound(); std::cout << std::endl;

	delete a; delete c; delete d;

	WrongAnimal *wc = new WrongCat;
	std::cout << std::endl << "wc sound: "; wc->makeSound(); std::cout << std::endl;
	delete wc;
}
