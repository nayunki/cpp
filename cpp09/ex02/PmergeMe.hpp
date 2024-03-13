#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>

class PmergeMe {
private:
    std::vector<char *> arg;
    size_t jacobIdx;
    size_t insertionCount;
    std::vector<size_t> jacobVec;

    double vecTime;
    std::vector<int> argVec;

    double deqTime;
    std::deque<int> argDeq;

    void putArgToCtn(char **argv);
    void makeJacobArr();
    void printVector(std::vector<int> vec);
    void printDeque(std::deque<int> deq);
    size_t setIndex(size_t currIdx);

    void bSearchVec(size_t idx, size_t elementSize, std::vector<int> & mainVec, std::vector<int> & pendVec);
    void insertVec(size_t len, size_t elementSize, std::vector<int> & mainVec, std::vector<int> & pendVec);
    void sortVector(size_t len, size_t elementSize);

    void bSearchDeq(size_t idx, size_t elementSize, std::deque<int> & mainDeq, std::deque<int> & pendDeq);
    void insertDeq(size_t len, size_t elementSize, std::deque<int> & mainDeq, std::deque<int> & pendDeq);
    void sortDeque(size_t len, size_t elementSize);

    PmergeMe(const PmergeMe & obj);
    PmergeMe & operator=(const PmergeMe & obj);
public:
    PmergeMe();
    ~PmergeMe();
    void execute(char **argv);
	class	invalidInput : public std::exception {
		const char *what() const throw();
	};
};

#endif