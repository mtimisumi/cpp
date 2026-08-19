#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <list>

int main()
{
	// works with vectors
	std::vector<int> vec{2, 6, 4, 7, 1};
	std::vector<int>::iterator it_v = easyfind(vec, 4);
	if (it_v == vec.end())
		std::cout << "find was not found\n";
	else
		std::cout << "find was found: " << *it_v << "\n";

	// works with arrays
	std::array<int, 3> arr = {3, 7, 8};
	std::array<int, 3>::iterator it_a = easyfind(arr, 9);
	if (it_a == arr.end())
		std::cout << "find was not found\n";
	else
		std::cout << "find was found: " << *it_a << "\n";

	// works withs lists
	std::list<int> lst = {6, 7, 8, 9, 10, 11};
	std::list<int>::iterator it_l = easyfind(lst, 10);
	if (it_l == lst.end())
		std::cout << "find was not found\n";
	else
		std::cout << "find was found: " << *it_l << "\n";
}