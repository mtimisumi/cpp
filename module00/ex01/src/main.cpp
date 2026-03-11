#include "PhoneBook.hpp"

void	addContact(PhoneBook& phoneBook)
{
	Contact		contact;

	contact.setFirstName(getPrompt("first name"));
	contact.setLastName(getPrompt("last name"));
	contact.setNickName(getPrompt("nick name"));
	contact.setPhoneNumber(getPrompt("phone number"));
	contact.setDarkestSecret(getPrompt("darkest secret"));

	phoneBook.setContact(contact);
}

void	searchContact(const PhoneBook& phoneBook)
{
	int	index;

	index = phoneBook.getIndex();
	if (index == 0)
	{
		std::cout << "No contacts to display" << std::endl;
		return ;
	}
	displayContacts(phoneBook, index);
	selectContact(phoneBook, index);
}

int	main(int argc, char *argv[])
{
	(void)argv;
	PhoneBook	phoneBook;
	std::string	input;

	if (argc != 1)
		return 0;
	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, input))
			std::exit(1);
		if (input == "ADD")
			addContact(phoneBook);
		else if (input == "SEARCH")
			searchContact(phoneBook);
		else if (input == "EXIT")
			break ;
	}
}