#include "Contact.hpp"

void	Contact::setFirstName(const std::string& firstName)
{
	m_firstName = firstName;
}

void	Contact::setLastName(const std::string& lastName)
{
	m_lastName = lastName;
}

void	Contact::setNickName(const std::string& nickName)
{
	m_nickName = nickName;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber)
{
	m_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret)
{
	m_darkestSecret = darkestSecret;
}

const std::string&	Contact::getFirstName()
{
	return (m_firstName);
}

const std::string&	Contact::getLastName()
{
	return (m_lastName);
}

const std::string&	Contact::getNickName()
{
	return (m_nickName);
}

const std::string&	Contact::getPhoneNumber()
{
	return (m_phoneNumber);
}

const std::string&	Contact::getDarkestSecret()
{
	return (m_darkestSecret);
}