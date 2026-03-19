#include "debugEnable.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

bool debugEnable = false;

int	main()
{
	Animal *animals[100];

	for (int i = 0; i < 50; i++)
		animals[i] = new Dog;
	for (int i = 50; i < 100; i++)
		animals[i] = new Cat;
	
	std::cout << "animal[0] type: " << animals[0]->getType(); std::cout << std::endl;
	std::cout << "animal[0] sound: "; animals[0]->makeSound(); std::cout << std::endl;

	std::cout << "animal[50] type: " << animals[50]->getType(); std::cout << std::endl;
	std::cout << "animal[50] sound: "; animals[50]->makeSound(); std::cout << std::endl;

	for (int i = 0; i < 99; i++)
		delete animals[i];

	debugEnable = true;
	Dog dog;
	Cat cat;

	// two seperate brains
	std::cout << "dog idea: " << dog.getIdea() << std::endl;
	std::cout << "cat idea: " << cat.getIdea() << std::endl;

	// because we have no virtual destructor this should leak the brain
	std::cout << std::endl;
	WrongAnimal* wrongCat = new WrongCat;
	delete wrongCat;
	std::cout << std::endl;

	// whereas this first looks for the derived class' destructor
	delete animals[99];
	std::cout << std::endl;
}