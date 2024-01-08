#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &intern)
{
	*this = intern;
}

Intern &Intern::operator=(Intern const &intern)
{
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	
}
// name[0] s, r, p로 나눠도 댈듯 ㅎ
// func[0], 1, 2로 나눠서? . . 아님 스위치? ㅎ. . 
// switch문은 enum / int 타입으로만 경우를 나눌 수 있다내요 ㅠ.ㅠ.ㅠ.ㅠ.
// 그래서 함수포인터의 사용이 강제됩니다 흑 흑흑흑긓!!!