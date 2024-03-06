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
};

#endif