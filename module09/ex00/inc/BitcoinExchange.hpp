#pragma once

#include <iostream>
#include <map>
#include <string>
#include <exception>
#include <fstream>
#include <sstream>
#include <iterator>

#define MIN_YEAR 2009
#define MAX_YEAR 2026


class BitcoinExchange
{
	private:
		std::map<std::string, float> _database;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void getConvertedAmount(const std::string& s) const;

	private:
		bool validLine(const std::string& line, char c4) const;
		bool validDate(int year, int month, int day) const;
		float getRate(const std::string& date) const;
		void outputLine(const std::string& line) const;

};