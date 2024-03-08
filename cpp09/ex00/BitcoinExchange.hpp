#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <exception>
# include <fstream>
# include <map>
# include <algorithm>

class BitcoinExchange {
private:
	std::map<std::string, float> dbMap;
	void printError(const std::string & errorMsg);
	bool isFloatStr(const std::string & str);
	bool isValidDate(std::string date);
	bool isValidYYYYMMDD(int year, int month, int day);
	bool isLeapYear(int year);
	void addLine(const std::string & line);
	float getMultiplied(std::string date, float value);
	void printLine(const std::string & line);
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange & obj);
	BitcoinExchange & operator=(const BitcoinExchange & obj);
	~BitcoinExchange();
	class	invalidDatabase : public std::exception {
		const char *what() const throw();
	};
	class	invalidInput : public std::exception {
		const char *what() const throw();
	};
	void printDbMap();
	void parseDb(const std::string & dbName);
	void parseInput(const std::string & dbName);
	static const std::string ERR_SMALLNUM; // when value is not a positive number
	static const std::string ERR_BADINPUT; // when the form of line is invalid
	static const std::string ERR_LARGENUM; // when the value is over thousand
};

#endif