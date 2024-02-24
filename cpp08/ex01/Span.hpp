#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>
# include <ctime>

class Span {
private:
    std::vector<int> vec;
    unsigned int len;
    Span();
public:
    Span(unsigned int N);
    Span(const Span & obj);
    Span & operator=(const Span & obj);
    ~Span();
    void addNumber(int num);
    void fillSpan();
    int shortestSpan();
    int longestSpan();
    static int getRandomNumber();
    // void print();
};

#endif