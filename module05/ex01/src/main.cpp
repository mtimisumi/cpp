#include "Form.hpp"

int	main()
{
	try
	{
		Form B("B", 50, 200);
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
	std::cout << A << std::endl;
	Bureaucrat lily("Lily", 3);
	std::cout << lily << std::endl;
	lily.signForm(A);
	std::cout << A << std::endl;
	Bureaucrat matilda("Matilda", 30);
	std::cout << matilda << std::endl;
	matilda.signForm(A);
	Bureaucrat denise("Denise", 2);
	std::cout << denise << std::endl;
	denise.signForm(A);
}