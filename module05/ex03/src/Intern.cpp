#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{}

Intern& Intern::operator=(const Intern& other)
{}

Intern::~Intern()
{}

AForm* Intern::createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& form, const std::string& target)
{
	static const std::string forms[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	static AForm* (Intern::*f[](const std::string&)) = {&Intern::createRobotomy, &Intern::createPresidential, &Intern::createShrubbery};

	for (int i = 0; i < FORM_COUNT; i++)
	{
		if (form == forms[i]) {
			std::cout << "Intern creates form: " << forms[i] << std::endl;
			return (this->*f[i](target));
		}
	}
	throw InvalidFormException();
}

const char* Intern::InvalidFormException::what() const noexcept
{
	return "Invalid form";
}