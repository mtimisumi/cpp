#include "PmergeMe.hpp"
#include <exception>


void parseArguments(PmergeMe& p, int argc, char *argv[])
{
	for (int i = 0; i < argc; i++)
	{
		size_t pos;
		int value;

		try {
			value = std::stoi(argv[i], &pos);
		}
		catch (const std::exception& e) {
			throw std::runtime_error(std::string("argument given is invalid: ") + argv[i]);
		}

		if (pos != std::string(argv[i]).length())
			throw std::runtime_error(std::string("argument given is invalid: ") + argv[i]);
		if (value < 0) 
			throw std::runtime_error(std::string("argument given is not positive: ") + argv[i]);
		// if (value < 1) 
			// throw std::runtime_error(std::string("argument given is not positive: ") + argv[i]);

		p.addNumber(value);
	}
}


int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Error: Need more arguments\n";
		return 1;
	}

	PmergeMe p;
	try
	{
		parseArguments(p, argc-1, ++argv);
		p.FordJohnson();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	}
}
// //                             1. 2. 3. 4. 5. 6.  7.  8.  9. 10.  11. 12. 13. 14. 15. 16. 17. 18. 19. 20. 21. 22. 23. 24. 25. 26. 27. 28.  29.  30.  31.  32.  33.
// const int maxComparisons[] = { 0, 1, 3, 5, 7, 10, 13, 16, 19, 22, 26, 30, 34, 38, 42, 46, 50, 54, 58, 62, 66, 71, 76, 81, 86, 91, 96, 101, 106, 111, 116, 121, 126};

// int main()
// {

// }