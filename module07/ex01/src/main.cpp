#include "iter.hpp"

int main()
{
	int int_arr[5] = {1, 2, 3, 4, 5};

	std::cout << "\nprint original:\n";
	iter(int_arr, 5, print<int>);

	// increment
	iter(int_arr, 5, increment);

	std::cout << "\nprint incremented:\n";
	iter(int_arr, 5, print<int>);


	std::string str_arr[2] = {"Hello", "Amsterdam"};

	std::cout << "\n\nprint original:\n";
	iter(str_arr, 2, print<std::string>);

	// change
	iter(str_arr, 2, change);

	std::cout << "\nprint changed:\n";
	iter(str_arr, 2, print<std::string>);
	std::cout << "\n\n";


	// works with const too
	const int const_arr[4] = {6, 7, 8, 9};
	iter(const_arr, 4, print<int>);
}