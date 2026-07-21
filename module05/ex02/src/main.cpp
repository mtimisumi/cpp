#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <sstream>

int	main()
{
	PresidentialPardonForm peasantKiara("Kiara");
	RobotomyRequestForm robotElla("Ella");
	ShrubberyCreationForm shrubbyTree("Tree");

	Bureaucrat emi("Emi", 5);
	std::cout << emi << std::endl << std::endl;

	emi.signForm(robotElla);
	emi.executeForm(robotElla);
	std::cout << std::endl;

	emi.signForm(peasantKiara);
	emi.executeForm(peasantKiara);
	std::cout << std::endl;

	emi.signForm(shrubbyTree);
	emi.executeForm(shrubbyTree);
	std::cout << std::endl;

	// printing the tree
	std::ostringstream ss;
	std::ifstream file("Tree_shrubbery");
	if (!file.is_open())
		return 1;
	ss << file.rdbuf();
	std::cout << ss.str() << std::endl;
	std::cout << std::endl;

	// invalid case
	ShrubberyCreationForm shrub("Shrub");
	Bureaucrat b("B", 150);

	b.executeForm(shrub);
	b.signForm(shrub);
}
