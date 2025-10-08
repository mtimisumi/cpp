/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:18:45 by winnitytrin       #+#    #+#             */
/*   Updated: 2025/10/08 15:35:06 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string firstName)
{
	m_firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
	m_lastName = lastName;
}

void Contact::setNickname(std::string nickname)
{
	m_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	m_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	m_darkestSecret = darkestSecret;
}

bool Contact::isEmpty()
{
	if (m_firstName.empty())
		return true;
	return false;
}

std::string Contact::getModString(std::string s)
{
	std::string x;

	if (s.length() <= 10)
		return s;
	x = s.substr(0, 8) + '.';
	return x;
}

void Contact::printElement(std::string element)
{
	std::cout << '|' << std::setw(10) << std::right << element;
}

void Contact::printContact(int index)
{
	std::string x = getModString(m_firstName);
	std::string y = getModString(m_lastName);
	std::string z = getModString(m_nickname);

	std::cout << std::setw(10) << std::right << index;
	printElement(x); printElement(y); printElement(z);
	std::cout << std::endl;
}

void Contact::printContactInfo()
{
	std::cout << "First name: " << m_firstName << std::endl;
	std::cout << "Last name: " << m_lastName << std::endl;
	std::cout << "Nickname: " << m_nickname << std::endl;
	std::cout << "Phone number: " << m_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << m_darkestSecret << std::endl;
}
