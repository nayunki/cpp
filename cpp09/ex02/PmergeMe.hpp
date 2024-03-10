#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>

class PmergeMe {
private:
    std::vector<int> vec;
    std::deque<int> deq;
    double vecTime;
    double deqTime;
    void printVector();
    void printDeque();
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