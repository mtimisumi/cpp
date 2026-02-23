#include <iostream>
#include "PhoneBook.hpp"

void	addContact(PhoneBook phoneBook)
{

}

int	main()
{
	PhoneBook phoneBook;
	std::string input;

	do
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, input))
			return (1);
		if (input == "ADD")
			addContact();
		else if (input == "SEARCH")
			searchContact();
	}
	while (input != "EXIT");
}