#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	for (int i = 1; i < argc; i++)
	{
		std::string s = argv[i];
		for (char &c: s)
		{
			c = toupper(c);
		}
		std::cout << s;
	}
	std::cout << std::endl;
}
