#include <iostream>
#include "PhoneBook.hpp"

const std::string&	getPrompt(const std::string& s)
{
	std::string	input;

	do
	{
		std::cout << "Enter " << s << ":";
		if (!std::getline(std::cin, input))
			std::exit(1);
	}
	while (input.empty());

	return (input);
}

void	addContact(PhoneBook& phoneBook)
{
	Contact	contact;

	contact.setFirstName(getPrompt("first name"));
	contact.setLastName(getPrompt("last name"));
	contact.setNickName(getPrompt("nick name"));
	contact.setPhoneNumber(getPrompt("phone number"));
	contact.setDarkestSecret(getPrompt("darkest secret"));

	phoneBook.setContact(contact);
}

void	displayContactSummary()
{

}

void	displayContactInfo(const Contact& contact)
{
	std::cout << contact.getFirstName() << std::endl;
}

void	searchContact(const PhoneBook& phoneBook)
{
	for (int i = 0; i < 8; i++)
	{
		displayContactSummary();
	}
}

int	main()
{
	PhoneBook	phoneBook;
	std::string	input;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, input))
			return (1);
		if (input == "ADD")
			addContact(phoneBook);
		else if (input == "SEARCH")
			searchContact(phoneBook);
		else if (input == "EXIT")
			break ;
	}
}