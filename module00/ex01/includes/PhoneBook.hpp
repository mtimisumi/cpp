#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		void	setContact(Contact& contact);

	private:
		Contact	m_contacts[8];
		int		m_index = 0;
};

#endif