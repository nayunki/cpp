#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>
# include <iomanip>

# define PLUS 1
# define MINUS 0

class ScalarConverter
{
// class must not be instanciable by users => singleton
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &obj);
	ScalarConverter & operator=(const ScalarConverter &obj);
public:
	~ScalarConverter();
	static void convert(std::string str);
};

bool isString(std::string str, double d);

#endif