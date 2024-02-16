#include "Array.hpp"
#define MAX_VAL 7

int main(int, char**)
{
    int *a = new int();
    std::cout << *a << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers; // 생성되지 않은 객체에 대입연산자를 사용할 경우 복사생성자 호출
        Array<int> test(tmp);

        for (unsigned int i = 0; i < tmp.size(); i++) {
            std::cout << tmp[i] << " ";
        }
        std::cout << std::endl;

        for (unsigned int i = 0; i < test.size(); i++) {
            std::cout << test[i] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i]) // mirror도 numbers도 모두 같은 원소 가지고 있어야 함
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0; // 접근 불가능한 인덱스 접근 시도, exception
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0; // 또한 접근 불가능한 인덱스, exception
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     numbers[i] = rand();
    // }

    delete [] mirror;

    // system("leaks Array");
    return 0;
}