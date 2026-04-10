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

	std::cout << "Printing robotomy form:\n" << *robotomyForm;

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
		std::cout << "Succesfully created form presidential pardon!\n";
	}
	catch(const std::exception& e) {
		std::cout << "Could not create form because: " << e.what() << std::endl;
	}
}