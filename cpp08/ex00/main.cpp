#include <vector>
#include <list>
#include "EasyFind.hpp"

int main() {
    try {
        std::vector<int> vec;
        std::list<int> li;
        for (int i = 0; i < 5; i++) {
            vec.push_back(i);
            li.push_back(i);
        }
        std::cout << "vector easyfind : " << *(EasyFind(vec, 2)) << std::endl;
        std::cout << "list easyfind : " << *(EasyFind(li, 2)) << std::endl;
        
        std::cout << "vector easyfind error : " << *(EasyFind(vec, 10)) << std::endl;
        std::cout << "list easyfind error : " << *(EasyFind(li, 10)) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}