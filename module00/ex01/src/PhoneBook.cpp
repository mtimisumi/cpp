/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winnitytrinnity <winnitytrinnity@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:18:50 by winnitytrin       #+#    #+#             */
/*   Updated: 2025/10/07 23:04:11 by winnitytrin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::setContact(Contact contact)
{
	m_contacts[m_index] = contact;
	m_index = (m_index + 1) % 8;
}

void PhoneBook::printContacts()
{
	for (int i = 0; i < 8; i++)
	{
		int index = (m_index - 1) % 8;
		if (m_contacts[index].isEmpty())
			return ;
		m_contacts[index].printContact(i);
		
	}
}

void PhoneBook::selectContact()
{
	std::string input;
	int			n;

	int index = 0;
	while (!m_contacts[index].isEmpty())
		index++;
	
	do{
		std::cout << "Enter a user index: ";
		if (!getline(std::cin, input))
			std::exit(1);
		n = std::stoi(input);
	}while (n < 1 || n > index);
	
	m_contacts[n].printContactInfo();
}

