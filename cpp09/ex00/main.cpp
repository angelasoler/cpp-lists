#include "BitcoinExchange.hpp"

std::map<std::string, double> data;

int	loadCSV() {
	std::fstream file;
	std::string line, date;
	double value;

	file.open("data.csv", std::ios::in);
	if (!file.is_open()) {
		std::cerr << "Error: Cannot open data.csv" << std::endl;
		return (1);
	}
	while (getline(file, line)) {
		std::stringstream ss(line);
		if (getline(ss, date, ',') && ss >> value) {
			data[date] = value;
		}
	}
	file.close();
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Error: Bad argument." << std::endl;
		return (1);
	}
	if (loadCSV())
		return (1);
	std::string	s(argv[1]);
	BitcoinExchange btc(s);
	btc.returnExchange();
}
