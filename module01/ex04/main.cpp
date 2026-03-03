#include <iostream>
#include <fstream>
#include <string>

typedef enum error
{
	ERROR_OPEN,

}			error;

void	exitError()
{

}

void	replacer(const std::string& file, const std::string& s1, const std::string& s2)
{
	std::string	replace;
	std::string	content;
	size_t		s1Len = s1.length();
	size_t		start = 0;

	std::ifstream(file) >> content;
	if (!content)
		exitError();
	while (start < content.length())
	{
		size_t pos = content.find(s1, start);
		content.erase(pos, s1Len);
		content.insert(pos, s2);
		start= pos + s1Len;
	}
	std::ofstream replace(file + ".replace");
	replace << content;
}

void	replacer(const std::string& file, const std::string& s1, const std::string& s2)
{
	std::ifstream
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return 1;
	replacer(argv[1], argv[2], argv[3]);
}