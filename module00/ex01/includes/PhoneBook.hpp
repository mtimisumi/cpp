#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

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

#endif