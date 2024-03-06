#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & obj) {
	*this = obj;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & obj) {
	(void)obj;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const char *BitcoinExchange::invalidDatabase::what() const throw() {
	return "Error: invalid database";
}

const char *BitcoinExchange::invalidInput::what() const throw() {
	return "Error: invalid input";
}