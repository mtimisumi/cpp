#pragma once

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define FORM_COUNT 3

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* createRobotomy(const std::string& target);
		AForm* createPresidential(const std::string& target);
		AForm* createShrubbery(const std::string& target);
		AForm* makeForm(const std::string& form, const std::string& target);

	private:
		class InvalidFormException: public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};
