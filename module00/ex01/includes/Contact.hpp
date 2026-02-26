#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	public:
		void	setFirstName(const std::string& firstName);
		void	setLastName(const std::string& lastName);
		void	setNickName(const std::string& nickName);
		void	setPhoneNumber(const std::string& phoneNumber);
		void	setDarkestSecret(const std::string& darkestSecret);

		const std::string&	getFirstName() const ;
		std::string&	getLastName();
		std::string&	getNickName();
		std::string&	getPhoneNumber();
		std::string&	getDarkestSecret();


	private:
		std::string	m_firstName;
		std::string	m_lastName;
		std::string	m_nickName;
		std::string	m_phoneNumber;
		std::string	m_darkestSecret;
};

#endif


// const int* a;
// int const * a;


/*
	std::string&	getFirstName();

	const std::string&	getFirstName() const ;


*/