#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat h("Henk", 233);
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception henk: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("Bob", 0);
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception bob: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	Bureaucrat e("Ella", 2);
	Bureaucrat k("Kiara", 149);

	std::cout << e << std::endl;
	std::cout << k << std::endl;

	e.incrementGrade();
	k.decrementGrade();

	std::cout << e << std::endl;
	std::cout << k << std::endl;

	try
	{
		e.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception Ella: " << e.what() << std::endl;
	}
	try
	{
		k.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception Kiara: " << e.what() << std::endl;
	}
}