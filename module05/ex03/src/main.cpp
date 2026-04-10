#include "Intern.hpp"

int	main()
{
	Intern judy;
	AForm* robotomyForm;
	AForm* presidentialForm;
	AForm* shrubberyForm;
	AForm* invalidForm;
	
	robotomyForm = judy.makeForm("robotomy request", "Camilla");
	presidentialForm = judy.makeForm("presidential pardon", "Charles");
	shrubberyForm = judy.makeForm("shrubbery creation", "Richard");

	std::cout << std::endl;
	std::cout << "Printing robotomy form:\n" << *robotomyForm << std::endl;
	std::cout << "Printing presidential form:\n" << *presidentialForm << std::endl;
	std::cout << "Printing shrubbery form:\n" << *shrubberyForm << std::endl;

	try
	{
		invalidForm = judy.makeForm("invalid form", "Bunny");
	}
	catch(const std::exception& e) {
		std::cout << "Could not create form because: " << e.what() << std::endl;
	}

	try
	{
		presidentialForm = judy.makeForm("presidential pardon", "Henry");
		std::cout << std::endl;
		std::cout << "Printing presidential form:\n" << *presidentialForm << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Could not create form because: " << e.what() << std::endl;
	}
}