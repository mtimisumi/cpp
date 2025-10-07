/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winnitytrinnity <winnitytrinnity@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:48:31 by mmisumi           #+#    #+#             */
/*   Updated: 2025/10/07 22:49:38 by winnitytrin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Contact.hpp"
#include <string>

class PhoneBook
{
	public:
		PhoneBook() : m_index(0){}

		void setContact(Contact contact);
		void printContacts();
		void selectContact();
		
	
	private:
		Contact	m_contacts[8];
		int 	m_index;
};
