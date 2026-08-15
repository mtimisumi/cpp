#include "Array.hpp"
#include <string>


int main()
{
	Array<int> a(0);
	std::cout << "Array a size: " << a.size() << "\n\n";
	
	Array<int> i(2);
	std::cout << "Array i size: " << i.size() << "\n";
	std::cout << "i[0] = " << i[0] << "\n";
	std::cout << "i[1] = " << i[1] << "\n\n";


	Array<std::string> s(3);
	// initializing s
	s[0] = "zero";
	s[1] = "one";
	s[2] = "two";
	std::cout << "Array s size: " << s.size() << "\n";
	std::cout << "s[0] = " << s[0] << "\n";
	std::cout << "s[1] = " << s[1] << "\n";
	std::cout << "s[2] = " << s[2] << "\n\n";
	try
	{
		s[3] = "three";
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << "\n\n";
	}

	Array<std::string> copy = s;
	std::cout << "Array copy size: " << s.size() << "\n";
	std::cout << "copy[0] = " << copy[0] << "\n";
	std::cout << "copy[1] = " << copy[1] << "\n";
	std::cout << "copy[2] = " << copy[2] << "\n";

}