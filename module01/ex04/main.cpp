#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#define ARGC "Error: invalid amount of arguments"
#define IFILE "Error: couldnt open file"
#define OFILE "Error: couldnt create file"
#define RDBUF "Error: rdbuf fail/bad"


void	errorMsg(const std::string& errorMessage)
{
	std::cerr << errorMessage << std::endl;
}

std::string	copyFileString(const std::ifstream& file)
{
	std::ostringstream	ss;

	ss << file.rdbuf();
	if (file.fail() || file.bad()) {
		errorMsg(RDBUF);
		return nullptr;
	}
	return ss.str();
}

std::string	replaceAll(std::string str, const std::string& s1, const std::string& s2)
{
	size_t	s1Len = s1.length();
	size_t	s2Len = s2.length();
	size_t	start = 0;

	if (s1.empty())
		return (str);
	while (start < str.length()) {
		size_t pos = str.find(s1, start);
		if (pos == std::string::npos)
			break ;
		str.erase(pos, s1Len);
		str.insert(pos, s2);
		start = pos + s2Len;
	}
	return str;
}

int	main(int argc, char *argv[])
{
	if (argc != 4) {
		errorMsg(ARGC);
		return 1;
	}

	std::ifstream inFile(argv[1]);
	if (!inFile) {
		errorMsg(IFILE);
		return 1;
	}

	std::string content = copyFileString(inFile);

	std::cout << content << std::endl;
	content = replaceAll(content, argv[2], argv[3]);
	std::cout << content << std::endl;

	std::ofstream outFile(std::string(argv[1]) + ".replace");
	if (!outFile) {
		errorMsg(OFILE);
		return 1;
	}

	outFile << content;
}
