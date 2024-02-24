#include "Span.hpp"

Span::Span(): len(0) {
}

Span::Span(unsigned int N): len(N) {
}

Span::Span(const Span & obj) {
    *this = obj;
}

Span & Span::operator=(const Span & obj) {
    if (this != &obj) {
        this->vec = obj.vec;
        this->len = obj.len;
    }
    return (*this);
}

Span::~Span() {
}

void Span::addNumber(int num){
    if (this->vec.size() >= this->len)
        throw std::exception();
    this->vec.push_back(num);
}

int Span::shortestSpan() {
    if (this->vec.size() <= 1)
        throw std::exception();

    std::vector<int> dup = this->vec; // 내부에서 깊은 복사 수행
    std::sort(dup.begin(), dup.end()); // dup 오름차순 정렬

    unsigned int span = 0;
    unsigned int res = INT_MAX;
    std::vector<int>::iterator it = dup.begin();
    for (;it != dup.end() - 1; it++) {
        span = *(it + 1) - *it; // *(it + 1)이 항상 더 큼
        if (span < res)
            res = span;
    }
    return (res);
}

int Span::longestSpan() {
    if (this->vec.size() <= 1)
        throw std::exception();

    int max = *std::max_element(this->vec.begin(), this->vec.end());
    int min = *std::min_element(this->vec.begin(), this->vec.end());
    return (max - min);
}