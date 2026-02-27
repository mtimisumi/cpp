#ifndef HEADER_HPP
# define HEADER_HPP

# include "PhoneBook.hpp"
# include <iostream>
# include <iomanip>

std::string	getPrompt(const std::string& s);
void		displayContacts(const PhoneBook& phoneBook, int index);
void		selectContact(const PhoneBook& phoneBook, int index);

#endif