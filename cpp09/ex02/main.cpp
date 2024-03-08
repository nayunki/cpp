#include "PmergeMe.hpp"

// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
int main(int argc, char **argv) {
    if (argc <= 2) {
        std::cerr << "Not enough argument!" << std::endl;
        return -1;
    }
    try {
        PmergeMe pmm;
        pmm.execute(argv);
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}