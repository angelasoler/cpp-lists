
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(std::string filename) : filename(filename) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
	{
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

void	printExchageLine(std::string date, double value)
{
	std::string	token[3];
	std::string	year;
	std::string	month;
	std::string	day;

	std::stringstream ss(date);
	if (getline(ss, year, '-')) {
		ss >> month;
		ss >> day;
	}
	else
		throw (InvalidInput("Error: invalid date"));
	if (std::atoi(year.c_str()) > 2022 || \
		std::atoi(month.c_str()) > 12 || \
		std::atoi(day.c_str()) > 31)
		throw (InvalidInput("Error: invalid date"));
	if (value < 0)
		throw (InvalidInput("Error: not a positive number."));
	std::map<std::string, double>::iterator it = data.lower_bound(date);
	if (it != data.begin() && it != data.end() && it->first != date)
		it--;
	if (value > INT_MAX)
		throw (InvalidInput("Error: too large a number."));
	std::cout << date << " => " << value << " = " << it->second * value << std::endl;
}

void	BitcoinExchange::returnExchange()
{
	std::fstream	file;
	std::string		line, date, token;
	double			value;
	bool			primeiraLinha = true;

	file.open(filename.c_str(), std::ios::in);
	if (!file.is_open()) {
		std::cerr << "Error: cannot open file" << std::endl;
		return ;
	}
	while (getline(file, line)) {
		if (primeiraLinha) {
			primeiraLinha = false;
			continue;
		}
		std::stringstream ss(line);
		if (getline(ss, date, '|') && ss >> value) {
			try
			{
				printExchageLine(date, value);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		else
			std::cerr << "Error: Bad input => " << date << std::endl;
	}
	file.close();
}

InvalidInput::InvalidInput(const char *msg) : msg(msg) {}

InvalidInput::~InvalidInput() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {}


const char *InvalidInput::what() const throw()
{
	return (msg.c_str());
}
