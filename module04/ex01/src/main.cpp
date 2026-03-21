#include "debugEnable.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

bool debugEnable = false;

int	main()
{
	Animal *animals[5];

	for (int i = 0; i < 5; i++) {
		if (i % 2 == 0)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
	}
	for (int i = 0; i < 5; i++) {
		std::cout << "animal[" << i << "] type: " << animals[i]->getType(); std::cout << std::endl;
		std::cout << "animal[" << i << "] sound: "; animals[i]->makeSound(); std::cout << std::endl;
	}

	for (int i = 0; i < 4; i++)
		delete animals[i];

	Cat *kat = new Cat;
	std::cout << "kat idea: " << kat->getIdea() << std::endl;
	kat->haveIdea("crazy idea");
	Cat *kitty = new Cat(*kat);
	std::cout << "kat idea: " << kat->getIdea() << std::endl;
	std::cout << "kitty idea: " << kitty->getIdea() << std::endl;

	*kitty = *kat;
	delete kat;
	std::cout << "kitty idea after destruction of kat: " << kitty->getIdea() << std::endl;
	delete kitty;

	debugEnable = true;

	// because we have no virtual destructor this should leak the brain
	std::cout << std::endl;
	WrongAnimal* wrongCat = new WrongCat;
	delete wrongCat;
	std::cout << std::endl;

	// whereas this first looks for the derived class' destructor
	delete animals[4];
	std::cout << std::endl;

	debugEnable = false;
}