/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winnitytrinnity <winnitytrinnity@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:18:56 by winnitytrin       #+#    #+#             */
/*   Updated: 2025/10/07 22:55:48 by winnitytrin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>

class Contact
{
	public:
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickname(std::string nickname);
	void setPhoneNumber(std::string phoneNumber);
	void setDarkestSecret(std::string darkestSecret);

	bool isEmpty();
	void printContact(int index);
	void printContactInfo();


	private:
		std::string	m_firstName;
		std::string	m_lastName;
		std::string	m_nickname;
		std::string	m_phoneNumber;
		std::string	m_darkestSecret;
		
		std::string getModString(std::string x);
		void 		printElement(std::string element);
};
