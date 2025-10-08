/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:18:50 by winnitytrin       #+#    #+#             */
/*   Updated: 2025/10/08 16:21:41 by mmisumi          ###   ########.fr       */
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
		if (m_contacts[i].isEmpty())
			return ;
		m_contacts[i].printContact(i);
	}
}

int PhoneBook::isUserInput(std::string s)
{
	int user_count = 0;
	int n;

	if (s.length() > 1)
		return -1;
	
	for (char c : s){
		if (!std::isdigit(c))
			return -1;
	}

	while(!m_contacts[user_count].isEmpty())
		user_count++;
	printf("user_count: %d\n", user_count);
	n = std::stoi(s);
	if (n < 0 || n >= user_count)
		return -1;

	return n;
}

void PhoneBook::selectContact()
{
	std::string input;
	int			n;

	int user_count = 0;
	while (!m_contacts[user_count].isEmpty())
		user_count++;
	
	do{
		std::cout << "Enter a user index: ";
		if (!getline(std::cin, input))
			std::exit(1);
		n = isUserInput(input);
	}while (n == -1);
	
	m_contacts[n].printContactInfo();
}

