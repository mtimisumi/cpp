#include "Intern.hpp"

int	main()
{
	Intern judy;
	AForm* robotomyForm;
	AForm* presidentialForm;
	AForm* shrubberyForm;
	AForm* invalidForm;
	
	robotomyForm = judy.makeForm("robotomy request", "Camilla");
	presidentialForm = judy.makeForm("presidential pardon", "Henry");
	shrubberyForm = judy.makeForm("shrubbery creation", "Charles");

	std::cout << std::endl;
	std::cout << *robotomyForm << std::endl;
	std::cout << *presidentialForm << std::endl;
	std::cout << *shrubberyForm << std::endl;

	try
	{
		invalidForm = judy.makeForm("invalid form", "Bunny");
	}
	catch(const std::exception& e) {
		std::cout << "Could not create form because: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	Bureaucrat lobster("Lobster", 10);
	lobster.signForm(*robotomyForm);
	lobster.executeForm(*robotomyForm);
	lobster.signForm(*presidentialForm);
	lobster.signForm(*presidentialForm); // already signed
	lobster.executeForm(*presidentialForm); // execute grade too low
	lobster.executeForm(*shrubberyForm); // form not signed

	delete robotomyForm;
	delete presidentialForm;
	delete shrubberyForm;
}