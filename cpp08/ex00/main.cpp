#include <vector>
#include <list>
#include "EasyFind.hpp"

# define FIND 2
# define FIND_MORE 10

int main() {
    try {
        std::vector<int> vec;
        std::list<int> li;

        // vec.push_back(100);
        // vec.push_back(124);
        // vec.push_back(99);
        // vec.push_back(0);
        // vec.push_back(2);

        for (int i = 0; i < 5; i++) {
            vec.push_back(i);
            li.push_back(i);
        }
        std::cout << "vector easyfind : " << *EasyFind(vec, FIND) << " is at index " 
            << EasyFind(vec, FIND) - vec.begin() << "." << std::endl;
        std::cout << "list easyfind : " << *EasyFind(li, FIND) << " is at index " 
            << std::distance(li.begin(), EasyFind(li, FIND)) << "." << std::endl;
        
        std::cout << "vector easyfind error : " << *EasyFind(vec, FIND_MORE) << " is at index " 
            << std::distance(vec.begin(), EasyFind(vec, FIND)) << "." << std::endl;
        std::cout << "list easyfind error : " << *EasyFind(li, FIND_MORE) << " is at index " 
            << std::distance(li.begin(), EasyFind(li, FIND)) << "." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}