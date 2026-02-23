#include "Contact.hpp"

void	Contact::setFirstName(std::string firstName)
{
	m_firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	m_lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	m_nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	m_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	m_darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName()
{
	return (m_firstName);
}

std::string	Contact::getLastName()
{
	return (m_lastName);
}

std::string	Contact::getNickName()
{
	return (m_nickName);
}

std::string	Contact::getPhoneNumber()
{
	return (m_phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
	return (m_darkestsecret);
}