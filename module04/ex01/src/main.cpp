# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

int	main()
{
	bool debugEnable = false;
	Animal *animals[100];

	for (int i = 0; i < 50; i++)
		animals[i] = new Dog;
	for (int i = 50; i < 100; i++)
		animals[i] = new Cat;
	
	std::cout << "animal[0] type: " << animals[0]->getType(); std::cout << std::endl;
	std::cout << "animal[0] sound: "; animals[0]->makeSound(); std::cout << std::endl;

	std::cout << "animal[50] type: " << animals[50]->getType(); std::cout << std::endl;
	std::cout << "animal[50] sound: "; animals[50]->makeSound(); std::cout << std::endl;

	for (int i = 0; i < 100; i++)
		delete animals[i];

	debugEnable = true;
	Dog dog;
	Cat cat;

	std::cout << "dog idea: " << dog.getIdea() << std::endl;
	std::cout << "cat idea: " << cat.getIdea() << std::endl;
}