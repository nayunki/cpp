#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::ERR_SMALLNUM = "Error: not a positive number.";
const std::string BitcoinExchange::ERR_BADINPUT = "Error: bad input => ";
const std::string BitcoinExchange::ERR_LARGENUM = "Error: too large a number.";

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & obj) {
	*this = obj;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & obj) {
	if (this != &obj)
		this->dbMap = obj.dbMap;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const char *BitcoinExchange::invalidDatabase::what() const throw() {
	return "Error: invalid database";
}

const char *BitcoinExchange::invalidInput::what() const throw() {
	return "Error: invalid input";
}

void BitcoinExchange::printError(const std::string & errorMsg) {
	std::cerr << errorMsg << std::endl;
	return ;
}

void BitcoinExchange::printDbMap() {
	std::map<std::string, float>::iterator it = this->dbMap.begin();
	for (; it != this->dbMap.end(); it++) {
		std::cout << it->first << " , " << it->second << std::endl;
	}
}

bool BitcoinExchange::isFloatStr(const std::string & str) {
	bool dotFlag = false;

	for (std::size_t i = 0; i < str.length(); i++) {
		if ((str[i] < '0' || '9' < str[i])) { // if str[i] is not a number
			if (str[i] == '.' && dotFlag == false)
				dotFlag = true;
			else
				return false;
		}
	}
	return true;
}

bool BitcoinExchange::isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}

bool BitcoinExchange::isValidYYYYMMDD(int year, int month, int day) {
	if (year <= 0 || month <= 0 || day <= 0 || month > 12 || day > 31)
		return false;

	int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year)) // 윤년
		months[1] = 29;

	if (day > months[month - 1])
		return false;

	return true;
}

bool BitcoinExchange::isValidDate(std::string date) {
	// "0000-00-00"
	if (date.length() != 10)
		return false;

	if (date.find('-') != 4 && date.find('-', 5) != 7)
		return false;

	int year = static_cast<int>(strtod(date.substr(0, 4).c_str(), NULL));
	int month = static_cast<int>(strtod(date.substr(5, 2).c_str(), NULL));
	int day = static_cast<int>(strtod(date.substr(8, 2).c_str(), NULL));

	if (!isValidYYYYMMDD(year, month, day))
		return false;
	return true;
}

void BitcoinExchange::addLine(const std::string & line) {
	std::string key;
	std::string value_str;
	float value;

	unsigned int i = line.find(',');
	if (i >= line.length() - 1)
		throw invalidDatabase();
	key = line.substr(0, i);
	value_str = line.substr(i + 1, line.length() - 1);
	if (!isValidDate(key) || !isFloatStr(value_str))
		throw invalidDatabase();
	value = static_cast<float>(strtod(value_str.c_str(), NULL));
	this->dbMap[key] = value;
}

void BitcoinExchange::parseDb(const std::string & dbName) {
	std::ifstream dbFile(dbName);
	if (!dbFile.is_open())
		throw invalidDatabase();
	
	std::string dbLine;
	std::getline(dbFile, dbLine);
	if (dbLine != "date,exchange_rate")
		throw invalidDatabase();

	while (dbFile) {
		if (dbFile.eof())
			break ;
		std::getline(dbFile, dbLine);
		if (dbLine != "")
			addLine(dbLine); // 내부에서 한줄씩 db 유효성검사
	}
}

// lower_bound 값 찾아서 계산 후 float return 하기
float BitcoinExchange::getMultiplied(std::string date, float value) {
	std::map<std::string, float>::iterator it = dbMap.upper_bound(date);
	// 그럼 db보다 더 미래의 값이 들어오면 it는 dbMap.end()가 되는거고 어차피 하나 빼니까 괜차는거임 ?ㅅ?
	if (it == dbMap.begin()) // data.csv 파일의 처음 date보다 더 이전이라서 값을 구할 수 업듬
		throw invalidInput();
	it--;
	return (it->second * value);
}

void BitcoinExchange::printLine(const std::string & line) {
	std::string date;
	std::string value_str;
	float value;

	unsigned int i = line.find('|');
	if (i >= line.length() - 1) {
		std::cerr << ERR_BADINPUT << line << std::endl;
		return ;
	}

	date = line.substr(0, i - 1);
	value_str = line.substr(i + 2, line.length() - 1);

	if (value_str[0] == '-' && isFloatStr(value_str.substr(1, value_str.length() - 1)))
		return (printError(ERR_SMALLNUM));

	if (!isValidDate(date) || !isFloatStr(value_str)) {
		std::cerr << ERR_BADINPUT << date << std::endl;
		return;
	}

	// data.csv에 음수 value 있을 땐 걍 invalid database
	value = static_cast<float>(strtod(value_str.c_str(), NULL));
	if (value > 999)
		return (printError(ERR_LARGENUM));
	if (value == 0)
		return (printError(ERR_SMALLNUM));

	std::cout << date << " => " << value << " = " << getMultiplied(date, value) << std::endl;
}

void BitcoinExchange::parseInput(const std::string & inputName) {
	std::ifstream inFile(inputName);
	if (!inFile.is_open())
		throw invalidInput();

	std::string line;
	std::getline(inFile, line);
	if (line != "date | value")
		throw invalidInput();

	while (inFile) {
		if (inFile.eof())
			break ;
		std::getline(inFile, line);
		if (line != "")
			printLine(line);
	}
}