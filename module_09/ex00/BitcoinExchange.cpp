#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
	loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_database = other._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_database = other._database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		size_t pos = line.find(',');
		std::string date = line.substr(0, pos);
		std::string rateStr = line.substr(pos + 1);
		float rate = std::atof(rateStr.c_str());

		_database[date] = rate;
	}	
}

static bool validateDate(const std::string &date, const std::string &line)
{
	if (date.length() != 10)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return false;
		}
		if (date[4] != '-' || date[7] != '-')
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return false;
		}
		bool valid = true;
		for (size_t i = 0; i < date.length(); i++)
		{
			if (i == 4 || i == 7)
				continue;

			if (!std::isdigit(date[i]))
			{
				valid = false;
				break;
			}
		}
		if (!valid)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return false;
		}
		int year = std::atoi(date.substr(0, 4).c_str());
		int month = std::atoi(date.substr(5, 2).c_str());
		int day = std::atoi(date.substr(8, 2).c_str());

		if (month < 1 || month > 12)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return false;
		}
		if (day < 1 || day > 31)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return false;;
		}
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return false;
		}
		if (month == 2 && day > 29)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return false;
		}
		bool leapYear = (year % 4 == 0 && year % 100 != 0)
					|| (year % 400 == 0);
		if (month == 2 && day == 29 && !leapYear)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return false;
		}
		return true;
}
static bool validateValue(double amount)
{
	if (amount < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (amount > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}	

float BitcoinExchange::getRate(const std::string &date)
{
	std::map<std::string, float>::iterator it = _database.find(date);

	if (it != _database.end())
		return it->second;

	it = _database.lower_bound(date);

	if (it == _database.begin())
		return -1;

	--it;
	return it->second;
}

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;

	while (std::getline(file, line))
	{
		if (line == "date | value")
			continue;

		size_t pos = line.find(" | ");

		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pos);
		double amount = std::atof(line.substr(pos + 3).c_str());
		if (!validateDate(date, line))
				continue;
		if (!validateValue(amount))
			continue;

		float rate = getRate(date);
		std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
	}
}

