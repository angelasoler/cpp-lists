
#include "BitcoinExchange.hpp"

// TO-DO
// [_] implementar execeptions
// [_] tratar large number

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
	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		// throw (negative_number());
		return ;
	}
	std::map<std::string, double>::iterator it = data.lower_bound(date);
	if (it != data.begin() && it != data.end() && it->first != date)
		it--;
	if (it == data.end() && date > it->first) {
		std::cerr << "Error: Bad input => " << date << std::endl;
		// throw (bad_input());
		return ;
	}
	if (value > INT_MAX) {
		std::cerr << "Error: too large a number." << std::endl;
		// throw (too_large_number());
		return ;
	}
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
		if (getline(ss, date, '|') && ss >> value)
			printExchageLine(date, value);
		else
			std::cerr << "Error: Bad input => " << date << std::endl;
	}
	file.close();
}
