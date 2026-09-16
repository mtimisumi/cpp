#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream database(std::string("data.csv"));
	if (!database)
		throw std::runtime_error("could not open file: data.csv");

	std::string line;
	std::getline(database, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("missing: \"date,exchange_rate\"");
	while (std::getline(database, line) && !line.empty())
	{
		if (!validLine(line, ','))
			throw std::runtime_error(std::string("bad input: " + line));
		std::string date = line.substr(0, 10);
		float rate = stof(line.substr(11));
		_database[date] = rate;	
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _database(other._database)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_database = other._database;

	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

void BitcoinExchange::getConvertedAmount(const std::string& s) const
{
	std::ifstream inFile(s);
	if (!inFile)
		throw std::runtime_error(std::string("could not open file: " + s));

	std::string line;
	std::getline(inFile, line);
	if (line != "date | value")
		throw std::runtime_error("missing: \"date | value\"");

	while (std::getline(inFile, line) && !line.empty())
	{
		try {
			outputLine(line);
		}
		catch(const std::exception& e) {
			std::cout << "Error: " << e.what() << "\n";
		}
	}
}

bool BitcoinExchange::validLine(const std::string& line, char c4) const
{
	std::istringstream iss(line);

	int year, month, day;
	char c1, c2, c3;
	float n;

	if (!(iss >> year >> c1 >> month >> c2 >> day >> c3 >> n) || !iss.eof())
		return false;
	
	if (c1 != '-' || c2 != '-' || c3 != c4)
		return false;
	if (!validDate(year, month, day))
		return false;
	if (n < 0)
		throw std::runtime_error("not a positive number.");
	if (c4 == '|' && n > 1000)
		throw std::runtime_error("too large a number.");

	return true;
}

bool BitcoinExchange::validDate(int year, int month, int day) const
{
	if (year < MIN_YEAR || year > MAX_YEAR)
		return false;
	if (month < 1 || month > 12)
		return false;

	const int monthDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day > monthDays[month-1])
		return false;

	if (month == 2 && (year%4 != 0) && day > 28)
		return false;

	return true;
}

float BitcoinExchange::getRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _database.upper_bound(date);
	if (it == _database.begin())
		throw std::runtime_error("date is too early.");
	--it;

	return (*it).second;
}

void BitcoinExchange::outputLine(const std::string& line) const
{
	if (!validLine(line, '|'))
		throw std::runtime_error(std::string("bad input : " + line));
	std::string date = line.substr(0, 10);
	float amount = stof(line.substr(13));
	float rate = getRate(date);
	std::cout << date << " => " << amount << " = " << amount*rate << "\n";
}