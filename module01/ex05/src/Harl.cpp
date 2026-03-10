#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	static void (Harl::*f[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	static const std::string logLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == logLevels[i]) {
			(this->*f[i])();
			return ;
		}
	}
	std::cout << "Error: Invalid level\n";
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-"
	<< "triple-pickle-specialketchup burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
	<< "You didn't put enough bacon in my burger! If you did, I wouldn't "
	<< "be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
	<< "I've been coming for years, whereas you started working here "
	<< "just last month.\n";
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
