#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

// any function to convert from a str to int (atoi), to a float or a double
// class must not be instanciable by users

void ScalarConverter::convert(std::string str) {
	std::stringstream ss;
	double d;
	bool sign = PLUS;

	if (str.front() == '+' || str.front() == '-') {
		if (str.front() == '-') {
			sign = MINUS;
		}
		str.erase(str.begin()); // 첫 문자 (부호) 제거
	}

	if (str.back() == 'f' && str != "inf")
		str.erase(str.end() - 1); // 마지막 문자 (float의 f) 제거

	ss << str;
	ss >> d;

	if (str == "" || (d == 0 && str != "0")) { // inf나 nan 아닌 문자열
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	if (str == "inf" || str == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	} else if (d > INT_MAX) {
		std::cout << "char: Non displayable" << std::endl;
		if (sign == MINUS && d == 2147483648)
			std::cout << "int: " << -2147483648 << std::endl;
		else
			std::cout << "int: Non displayable" << std::endl;
	} else if (d < 33 || d > 129) { // 32 ~ 128까지 printable
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	} else {
		std::cout << "char: " << static_cast<char>(d) << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}

// float이랑 double .0은 내가 붙여줘야 하는걸까.? ㅠ ㅠ
// double을 string으로 바꿨을 때 .이 없으면 .0을 붙여주자 . . !
//	find(str.begin(), str.end(), '.')
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
