#include "Base.hpp"

Base::~Base() {
}

A::~A() {
}

B::~B() {
}

C::~C() {
}

Base * generate(void) {
	Base * ret;

	srand(time(NULL));
	if (rand() % 3 == 0)
		ret = new A();
	else if (rand() % 3 == 1)
		ret = new B();
	else // (rand() % 3 == 2)
		ret = new C();
	return (ret);
}

void identify(Base* p) { // 포인터는 null이 있는데도 exception을 던지네 . . 그걸 다음 함수 catch에서 잡아버리네 . . 이해가 안가네 . . 
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Pointer of Base class" << std::endl;
}

void identify(Base& p) { // reference는 Null 없어서 실패시 std::bad_cast throw
	A a = dynamic_cast<A &>(p);
	B b = dynamic_cast<B &>(p);
	C c = dynamic_cast<C &>(p);
	// try {
		std::cout << "A" << std::endl;
		std::cout << "B" << std::endl;
		std::cout << "C" << std::endl;
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// try {
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// try {
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }
}