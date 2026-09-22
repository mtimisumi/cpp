#include "PmergeMe.hpp"
#include <exception>
#include <cmath>

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

		p.addNumber(value);
	}
}

int getMaxComparisons(int nbCount)
{
	int maxComparisons = 0;

	for (int k = 1; k <= nbCount; ++k)
		maxComparisons += static_cast<int>(
			std::ceil(std::log2((3.0 * k) / 4.0)));

	return maxComparisons;
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

// std::vector<int> getRandomVector(int amount)
// {
// 	std::vector<int> v;
// 	for (int i = 0; i < amount; i++)
// 		v.push_back(rand() % 1000);

// 	return v;
// }

// std::vector<int> getRandomShuffle(int amount)
// {
// 	std::vector<int> v;
// 	for (int i = 0; i < amount; i++)
// 		v.push_back(i);

// 	for (size_t i = v.size()-1; i > 0; i--)
// 	{
// 		size_t j = std::rand() % (i+1);
// 		std::swap(v[i], v[j]);
// 	}

// 	return v;
// }

// int main()
// {
// 	static bool seeded = false;
// 	if (!seeded)
// 	{
// 		std::srand(std::time(NULL));
// 		seeded = true;
// 	}

// 	PmergeMe p;

// 	std::vector<int> v1 = getRandomVector(25);
// 	p.putContainer(v1);
// 	p.FordJohnson();
// 	p.validateContainer();

// 	std::vector<int> v2 = getRandomShuffle(101);
// 	p.putContainer(v2);
// 	p.FordJohnson();
// 	p.validateContainer();

// 	std::vector<int> v3 = getRandomVector(300);
// 	p.putContainer(v3);
// 	p.FordJohnson();
// 	p.validateContainer();

// 	std::vector<int> v4 = getRandomShuffle(700);
// 	p.putContainer(v4);
// 	p.FordJohnson();
// 	p.validateContainer();

// 	std::vector<int> v5 = getRandomVector(3001);
// 	p.putContainer(v5);
// 	p.FordJohnson();
// 	p.validateContainer();

// 	std::vector<int> v6 = getRandomShuffle(3049);
// 	p.putContainer(v6);
// 	p.FordJohnson();
// 	p.validateContainer();
// }