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

bool isString(std::string str, double d) {
	if (d != 0)
		return false;

	bool dot = false;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '.' && dot)
			return true;
		else if (str[i] == '.')
			dot = true;
		else if (str[i] == '0')
			;
		else
			return true;
	}
	return false;
	// str이 0과 .으로만 이루어져있는지 확인.. 근데 .은 한번만 있어야됨 .. <- 사실 다른 소수들에선 고려 x
	// str 한 글자씩 보면서 0이면 넘어가기, .이면 체크, 다른거면 리턴 1
}

void ScalarConverter::convert(std::string str) {
	char *end;
	double d;
	std::string sign = "";
	std::string zero = "";

	if (str.front() == '+' || str.front() == '-') {
		if (str.front() == '-') {
			sign = "-";
		}
		str.erase(str.begin()); // 첫 문자 (부호) 제거
	}

	if (str.back() == 'f' && str != "inf")
		str.erase(str.end() - 1); // 마지막 문자 (float의 f) 제거

	d = strtod(str.c_str(), &end);

	if (str == "" || isString(str, d)) { // inf나 nan 아닌 문자열
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
		if (sign == "-" && d == 2147483648)
			std::cout << "int: " << -2147483648 << std::endl;
		else
			std::cout << "int: Non displayable" << std::endl;
	} else if (sign == "" && 32 <= d && d < 129) { // 32 ~ 128까지 printable
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << sign << static_cast<int>(d) << std::endl;
	}

	if (static_cast<int>(d) == d)
		zero = ".0";

	std::cout << "float: " << sign << static_cast<float>(d) << zero << "f" << std::endl;
	std::cout << std::setprecision(16);
	std::cout << "double: " << sign << d << zero << std::endl;
}