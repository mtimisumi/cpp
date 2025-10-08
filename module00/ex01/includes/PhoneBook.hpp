/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:48:31 by mmisumi           #+#    #+#             */
/*   Updated: 2025/10/08 16:07:10 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Contact.hpp"
#include <string>
#include <string_view>
#include <sstream>

class PhoneBook
{
	public:
		PhoneBook() : m_index(0){}

		void setContact(Contact contact);
		void printContacts();
		void selectContact();
		int  isUserInput(std::string input);
	
	private:
		Contact	m_contacts[8];
		int 	m_index;
};
