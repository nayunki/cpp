#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>

# define PLUS 1
# define MINUS 0

class ScalarConverter
{
// class must not be instanciable by users => singleton
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &obj);
public:
	ScalarConverter & operator=(const ScalarConverter &obj);
	~ScalarConverter();
	static void convert(std::string str);
};

#endif