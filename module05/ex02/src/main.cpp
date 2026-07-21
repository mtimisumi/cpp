#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <sstream>

int	main()
{
	PresidentialPardonForm peasantKiara("Kiara");
	RobotomyRequestForm robotElla("Ella");
	ShrubberyCreationForm shrubbyTree("Tree");

	Bureaucrat emi("Emi", 6);
	std::cout << emi << std::endl << std::endl;

	emi.signForm(robotElla);
	emi.signForm(shrubbyTree);
	emi.signForm(peasantKiara);
	std::cout << std::endl;

	std::cout << "Emi executing form robotElla:\n"; emi.executeForm(robotElla);
	std::cout << std::endl;
	std::cout << "Emi executing form shrubbyTree:\n"; emi.executeForm(shrubbyTree);
	// printing the tree
	std::ostringstream ss;
	std::ifstream file("Tree_shrubbery");
	ss << file.rdbuf();
	if (file) {
		std::cout << ss.str() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Emi executing form peasantKiara:\n"; emi.executeForm(peasantKiara);
	std::cout << std::endl;

	// incrementing grade 5 to 6
	emi.incrementGrade();
	std::cout << emi << std::endl;
	std::cout << "Emi executing form peasantKiara:\n"; emi.executeForm(peasantKiara); std::cout << std::endl;
}
