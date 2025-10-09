/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winnitytrinnity <winnitytrinnity@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:18:56 by winnitytrin       #+#    #+#             */
/*   Updated: 2025/10/09 22:12:27 by winnitytrin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>

class Contact
{
	public:
		void setFirstName(const std::string& firstName);
		void setLastName(const std::string& lastName);
		void setNickname(const std::string& nickname);
		void setPhoneNumber(const std::string& phoneNumber);
		void setDarkestSecret(const std::string& darkestSecret);
	
		bool isEmpty();
		void printContact(const int index);
		void printContactInfo();


	private:
		std::string getModString(const std::string& x);
		void 		printElement(const std::string& element);

	private:
		std::string	m_firstName;
		std::string	m_lastName;
		std::string	m_nickname;
		std::string	m_phoneNumber;
		std::string	m_darkestSecret;
		
};
