#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>

# define PLUS 1
# define MINUS 0

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &obj);
	ScalarConverter & operator=(const ScalarConverter &obj);
	~ScalarConverter();
	static void convert(std::string str);
};

#endif