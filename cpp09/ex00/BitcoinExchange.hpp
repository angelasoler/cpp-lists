
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <exception>
#include <fstream>
#include <climits>

extern std::map<std::string, double> data;

class BitcoinExchange
{
	private:
		std::string	filename;
	public:
		BitcoinExchange(void);
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange(void);
		void	returnExchange(void);
};

#endif /* BITCOINEXCHANGE_HPP */
