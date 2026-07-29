#include "iter.hpp"

int main()
{
	int int_arr[5] = {1, 2, 3, 4, 5};

	// print original
	iter(int_arr, 5, print<int>);
	std::cout << "\n";
	// increment
	iter(int_arr, 5, increment);
	// print incremented
	iter(int_arr, 5, print<int>);
	std::cout << "\n\n";



	std::string str_arr[2] = {"Hello", "Amsterdam"};

	// print original
	iter(str_arr, 2, print<std::string>);
	std::cout << "\n";
	// change
	iter(str_arr, 2, change);
	// print changed
	iter(str_arr, 2, print<std::string>);
	std::cout << "\n";


	// works with const too
	const int const_arr[4] = {6, 7, 8, 9};
	iter(const_arr, 4, print<int>);
}