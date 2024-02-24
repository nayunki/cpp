#include "MutantStack.hpp"
#include <list>

/*
아래의 동일한 코드를 한 번은 MutantStack으로, 다른 한 번은 ex) list로 실행해서 동일한 결과가 나오는지 확인하라.
서로 다른 컨테이너를 사용할 때에는 push()를 push_back()으로 바꾸는 등 적절한 멤버함수를 사용하라. 
*/

int main()
{
    MutantStack<int> mstack;

    std::cout << "------Test MutantStack begin-----" << std::endl;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    std::cout << "------Test MutantStack end-----" << std::endl;
    std::cout << "///////////////////////////////" << std::endl;
    std::cout << "------Test std::list begin-----" << std::endl;

    std::list<int> li;

    li.push_back(5);
    li.push_back(17);

    std::cout << li.back() << std::endl;

    li.pop_back();

    std::cout << li.size() << std::endl;

    li.push_back(3);
    li.push_back(5);
    li.push_back(737);
    li.push_back(0);

    std::list<int>::iterator itLi = li.begin();
    std::list<int>::iterator iteLi = li.end();

    ++itLi;
    --itLi;

    while (itLi != iteLi)
    {
        std::cout << *itLi << std::endl;
        ++itLi;
    }

    std::list<int> sLi(li);

    std::cout << "------Test std::list end-----" << std::endl;

    return 0;
}