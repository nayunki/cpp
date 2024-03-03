#include <vector>
#include <list>
#include "easyfind.hpp"

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
        std::cout << "vector easyfind : " << *easyfind(vec, FIND) << " is at index " 
            << easyfind(vec, FIND) - vec.begin() << "." << std::endl;
        std::cout << "list easyfind : " << *easyfind(li, FIND) << " is at index " 
            << std::distance(li.begin(), easyfind(li, FIND)) << "." << std::endl;
        
        std::cout << "vector easyfind error : " << *easyfind(vec, FIND_MORE) << " is at index " 
            << std::distance(vec.begin(), easyfind(vec, FIND)) << "." << std::endl;
        std::cout << "list easyfind error : " << *easyfind(li, FIND_MORE) << " is at index " 
            << std::distance(li.begin(), easyfind(li, FIND)) << "." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}