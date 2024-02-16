#include "EasyFind.hpp"

int main() {
    try {
        std::vector<int> vec;
        for (int i = 0; i < 5; i++) {
            vec[i] = i;
        }
        std::cout << "first easyfind : " << EasyFind(vec, 2) << std::endl;
        std::cout << "second easyfind : " << EasyFind(vec, 10) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}