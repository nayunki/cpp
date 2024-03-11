#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector> // pair도 포함
# include <deque>
# include <algorithm>
# include <ctime>

class PmergeMe {
private:
    std::vector<char *> arg;

    std::vector<int> argVec;
    std::vector<int> jacobVec;
    std::vector<int> mainVec;
    std::vector<int> pendVec;
    std::vector<int> sortedVec;
    std::vector<std::pair<int, int> > pairVec;

    std::deque<int> argDeq;
    std::deque<int> jacobDeq;
    std::deque<int> mainDeq;
    std::deque<int> pendDeq;
    std::deque<int> sortedDeq;
    std::deque<std::pair<int, int> > pairDeq;

    double vecTime;
    double deqTime;

    void putArgToCtn(char **argv);
    void printVector(std::vector<int> vec);
    void makeJacobArrVec();
    void bSearchVec(int end, int target);
    void mergePairVec(int begin, int mid, int end);
    void sortPairVec(int begin, int end);
    void sortVector();

    void printDeque(std::deque<int> deq);
    void makeJacobArrDeq();
    void bSearchDeq(int end, int target);
    void mergePairDeq(int begin, int mid, int end);
    void sortPairDeq(int begin, int end);
    void sortDeque();
public:
    PmergeMe();
    PmergeMe(const PmergeMe & obj);
    PmergeMe & operator=(const PmergeMe & obj);
    ~PmergeMe();
    void execute(char **argv);
	class	invalidInput : public std::exception {
		const char *what() const throw();
	};
};

#endif