#include "Form.hpp"

int	main()
{
	try
	{
		Form B("B", 200, 50);
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception form B: " << e.what() << std::endl;
	}
	try
	{
		Form C("C", 10, 0);
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception form C: " << e.what() << std::endl;
	}

	Form A("A", 10, 5);
	Bureaucrat lily("Lily", 30);
	lily.signForm(A);
	Bureaucrat matilda("Matilda", 3);
	matilda.signForm(A);
}