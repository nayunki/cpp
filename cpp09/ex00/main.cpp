#include "BitcoinExchange.hpp"

void addElement(const std::string & line, std::map<std::string, float> & dataMap) {
	std::string key;
	std::string value_str;
	char **end_ptr = NULL;
	float value;

	for (int i = 0; line[i]; i++) {
		if (line[i] == ',') { // "x" = const char * / 'x' = char
			key = line.substr(0, i);
			value_str = line.substr(i + 1, line.length() - 1);
			value = static_cast<float>(strtod(value_str.c_str(), end_ptr));
			dataMap[key] = value;
			break ;
		}
	}
}

void printMap(std::map<std::string, float> & dataMap) {
	std::map<std::string, float>::iterator it = dataMap.begin();
	for (; it != dataMap.end(); it++) {
		std::cout << it->first << " , " << it->second << std::endl;
	}
}

bool isValidInput(std::string line) {
	/*
	date | value
	0000-00-00 | 1000.00000000
	*/
	
	return true;
}

int main(int argc, char **argv) {
	try {
		(void)argv;		
		if (argc != 2)
			throw BitcoinExchange::invalidInput();

		std::cout.precision(7);
		BitcoinExchange btc;
		// 데이터는 에러없다고 가정 가능 ? ㅎ..
		std::ifstream dataFile("data.csv");
		if (!dataFile.is_open())
			throw BitcoinExchange::invalidDatabase();
		
		std::map<std::string, float> dataMap;
		std::string dataLine;
		while (dataFile) {
			getline(dataFile, dataLine);
			addElement(dataLine, dataMap);
		}
		// printMap(dataMap);

		std::ifstream inFile(argv[1]);
		if (!inFile.is_open())
			throw BitcoinExchange::invalidInput();

		std::string line;
		while (inFile) {
			getline(inFile, line);
			if (isValidInput(line)) {
				// 변환 후 출력
			}
		}

		/*
		2011-01-03 => 3 = 0.9
		2011-01-03 => 2 = 0.6
		2011-01-03 => 1 = 0.3
		2011-01-03 => 1.2 = 0.36
		Error: not a positive number.
		2011-01-09 => 1 = 0.32
		Error: bad input => 2001-42-42
		2012-01-11 => 1 = 7.1
		Error: too large a number.
		*/
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
    return 0;
}