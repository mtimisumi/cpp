#include "PhoneBook.hpp"

void	PhoneBook::setContact(Contact& contact)
{
	m_contacts[m_index % 8] = contact;
	m_index += 1;
}

const Contact&	PhoneBook::getContact(int index) const
{
	return (m_contacts[index]);
}

int	PhoneBook::getIndex() const
{
	return (m_index);
}