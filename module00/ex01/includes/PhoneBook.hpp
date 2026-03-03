#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
	public:
		void	setContact(Contact& contact);

		const Contact&	getContact(int index) const;
		int				getIndex() const;

	private:
		Contact	m_contacts[8];
		int		m_index = 0;
};

std::string	getPrompt(const std::string& s);
void		displayContacts(const PhoneBook& phoneBook, int index);
void		selectContact(const PhoneBook& phoneBook, int index);

#endif