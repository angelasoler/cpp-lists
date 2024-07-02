
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <exception>
#include <fstream>
#include <climits>
#include <cstdlib>

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

class InvalidInput : public std::exception {
	private:
		const std::string msg;
	public:
		InvalidInput(const char *msg);
		virtual ~InvalidInput() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
		virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
};

#endif /* BITCOINEXCHANGE_HPP */
