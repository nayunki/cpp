#include "Span.hpp"

int main() {
    try {
        Span a(10000);
        for (int i = 0; i < 9999; i++) {
            a.addNumber(i);
        }
        // a.fillSpan();
        a.addNumber(20000);
        std::cout << "Shortest span : " << a.shortestSpan() << std::endl;
        std::cout << "Longest span : " << a.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

// int main()
// {
//     Span sp = Span(5);

//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);

//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;

//     return 0;
// }