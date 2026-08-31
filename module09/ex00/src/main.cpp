#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Invalid argument count\n";
		return 1;
	}

	try {
		BitcoinExchange b;
		b.getConvertedAmount(argv[1]);
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	}
}