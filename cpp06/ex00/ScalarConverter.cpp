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

void ScalarConverter::convert(std::string str) {
	std::stringstream ss;
	double d;
	// bool sign = PLUS;
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

	ss << str;
	ss >> d;

	// 하 ......... 이렇게했더니 0.0부터 impossible나옴 ㅠㅠ !!! find 0 / . 해서 아닌거 있는 걸 걸러야 할까 ?
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

	if (static_cast<int>(d) == d) // => .0 추가
		zero = ".0";

	std::cout << "float: " << sign << static_cast<float>(d) << zero << "f" << std::endl;
	std::cout << "double: " << sign << d << zero << std::endl;
}
// float이랑 double은 inf 있어서 오버플로우 안 일어나는 거에요?ㅅ?