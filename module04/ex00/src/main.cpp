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

	WrongAnimal *wa = new WrongAnimal;
	WrongAnimal *wc = new WrongCat;

	std::cout << std::endl << "wa type: " << wa->getType() << std::endl;
	std::cout << "wa sound: "; wa->makeSound(); std::cout << std::endl;

	// the type does get updated correctly as we do call the wrongcat constructor
	std::cout << "wc type: " << wc->getType() << std::endl;
	std::cout << "wc sound: "; wc->makeSound(); std::cout << std::endl;

	// the compiler still only looks at the pointer's type
	(*wc).makeSound();

	delete wa; delete wc;
}
