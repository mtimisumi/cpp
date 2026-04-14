#include "Form.hpp"

int	main()
{
	try
	{
		Form B("B", 200, 50);
		std::cout << B << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception form B: " << e.what() << std::endl;
	}
	try
	{
		Form C("C", 10, 0);
		std::cout << C << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception form C: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	Form A("A", 10, 5);
	Bureaucrat lily("Lily", 30);
	std::cout << lily << std::endl;
	lily.signForm(A);
	std::cout << A << std::endl;
	Bureaucrat matilda("Matilda", 3);
	std::cout << matilda << std::endl;
	matilda.signForm(A);
	std::cout << A << std::endl;
}