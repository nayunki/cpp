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
    // std::deque<int> jacobDeq;
    std::deque<int> firstDeq;
    std::deque<int> secondDeq;
    std::deque<int> sortedDeq;
    std::deque<std::pair<int, int> > pairDeq;
    double vecTime;
    double deqTime;
    void printVector(std::vector<int> vec);
    void printDeque();
    void putArgToCtn(char **argv);
    void makeJacobArr();
    void bSearchVec(int end, int target);
    void sortVector();
    // void sortDeque();
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