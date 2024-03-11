#include "BitcoinExchange.hpp"



int main(int argc, char **argv) {
	try {
		if (argc != 2)
			throw BitcoinExchange::invalidInput();

		std::cout.precision(7);
		BitcoinExchange btc;
		btc.parseDb("data.csv");
		// btc.printDbMap(); // data.csv 저장 확인 완료
		btc.parseInput(argv[1]);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
    return 0;
}