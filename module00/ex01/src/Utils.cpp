#include "Header.hpp"

std::string	getPrompt(const std::string& s)
{
	std::string	input;

	do
	{
		std::cout << "Enter " << s << ": ";
		if (!std::getline(std::cin, input))
			std::exit(1);
	}
	while (input.empty());

	return (input);
}

static std::string	getModString(const std::string& s)
{
	if (s.length() > 10)
		s.substr(0, 8) + '.';
	return (s);
}

static void	printField(const std::string& field)
{
	std::cout << '|' << std::setw(10) << std::right << field;
}

static void	displayContactSummary(const Contact& contact, int index)
{
	std::cout << std::setw(10) << std::right << index;
	printField(getModString(contact.getFirstName()));
	printField(getModString(contact.getLastName()));
	printField(getModString(contact.getNickName()));
	std::cout << std::endl;
}

void	displayContacts(const PhoneBook& phoneBook, int index)
{
	for (int i = 0; i < 8; i++)
	{
		if (i == index)
			break ;
		displayContactSummary(phoneBook.getContact(i), i + 1);
	}
}

static void	displayContactInfo(const Contact& contact)
{
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nick Name: " << contact.getNickName() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

void	selectContact(const PhoneBook& phoneBook, int index)
{
	std::string	input;
	int			i;

	while (1)
	{
		std::cout << "Enter an index of the contact to display: ";
		if (!getline(std::cin, input))
			std::exit(1);
		i = std::stoi(input);
		if (i <= index && i > 0)
			break ;
	}
	displayContactInfo(phoneBook.getContact(i - 1));
}
