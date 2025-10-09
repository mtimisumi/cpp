/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winnitytrinnity <winnitytrinnity@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:52:57 by mmisumi           #+#    #+#             */
/*   Updated: 2025/10/09 22:29:52 by winnitytrin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	getPrompt(std::string_view s)
{
	std::string x;

	do{
		std::cout << "Enter " << s << ": ";
		if (!std::getline(std::cin, x))
			std::exit(1);
	}
	while(x.empty());
	return (x);
}

void	addContact(PhoneBook& phoneBook)
{
	Contact contact;

	contact.setFirstName(getPrompt("first name"));
	contact.setLastName(getPrompt("last name"));
	contact.setNickname(getPrompt("nickname"));
	contact.setPhoneNumber(getPrompt("phone number"));
	contact.setDarkestSecret(getPrompt("darkest secret"));

	phoneBook.setContact(contact);
}

void	searchContact(PhoneBook& phoneBook)
{
	phoneBook.printContacts();
	phoneBook.selectContact();
}

int	main(int argc, char *argv[])
{
	PhoneBook phoneBook;
	std::string x;
	
	if (argc != 1)
	return 0;

	do{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, x))
			return 1;
		if (x == "ADD")
			addContact(phoneBook);
		if (x == "SEARCH")
			searchContact(phoneBook);
	}
	while(x != "EXIT");

	(void)argv;
}
