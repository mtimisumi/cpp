#include "PhoneBook.hpp"

void	PhoneBook::setContact(Contact& contact)
{
	m_contacts[m_index % 8] = contact;
	m_index += 1;
}

void	PhoneBook::displayContactSummary()
{

}

void	PhoneBook::displayContactInfo()
{

}