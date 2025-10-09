/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winnitytrinnity <winnitytrinnity@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:48:31 by mmisumi           #+#    #+#             */
/*   Updated: 2025/10/09 22:23:37 by winnitytrin      ###   ########.fr       */
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
		void setContact(const Contact& contact);
		void printContacts();
		void selectContact();
		
	private:
		Contact	m_contacts[8];
		int 	m_index = 0;

		int isUserInput(const std::string& input);
};
