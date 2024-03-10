#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & obj) {
    *this = obj;
}

PmergeMe & PmergeMe::operator=(const PmergeMe & obj) {
    if (this != &obj) {
        this->vec = obj.vec;
        this->deq = obj.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

const char *PmergeMe::invalidInput::what() const throw() {
	return "Invalid Input";
}

void PmergeMe::printVector() {
    std::cout << "Print Vector\n";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque() {
    std::cout << "Print Deque\n";
    for (size_t i = 0; i < deq.size(); i++) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;   
}

void PmergeMe::execute(char **argv) {
    std::cout << "Before: ";
    for (size_t i = 0; argv[i]; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    sortVector();

    std::cout << "After: ";
    for (size_t i = 0; vec[i]; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    sortDeque();

    std::cout << "Time to process a range of " << vec.size()
     << " elements with std::vector : " << vecTime << "us\n";
    std::cout << "Time to process a range of " << vec.size()
     << " elements with std::deque : " << deqTime << "us\n";
}