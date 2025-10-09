/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winnitytrinnity <winnitytrinnity@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:18:50 by winnitytrin       #+#    #+#             */
/*   Updated: 2025/10/09 22:30:09 by winnitytrin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::setContact(const Contact& contact)
{
	m_contacts[m_index] = contact;
	m_index = (m_index + 1) % 8;
}

void PhoneBook::printContacts()
{
	for (int i = 0; i < 8; i++)
	{
		if (m_contacts[i].isEmpty())
			return ;
		m_contacts[i].printContact(i);
	}
}

int PhoneBook::isUserInput(const std::string& s)
{
	int user_count = 0;
	int n;

	if (s.length() > 1)
		return -1;
	
	for (char c : s){
		if (!std::isdigit(c))
			return -1;
	}

	for (int i = 0; i < 8; i++){
		if (m_contacts[user_count].isEmpty())
			break ;
		user_count++;
	}
	n = std::stoi(s);
	if (n < 0 || n >= user_count)
		return -1;

	return n;
}

void PhoneBook::selectContact()
{
	std::string input;
	int			n;

	if (m_contacts[0].isEmpty())
		return ;
	do{
		std::cout << "Enter a user index: ";
		if (!getline(std::cin, input))
			std::exit(1);
		n = isUserInput(input);
	}while (n == -1);
	
	m_contacts[n].printContactInfo();
}
