#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

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

void identify(Base* p) {
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
	try {
		A a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception & e) {
	}
	try {
		B b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception & e) {
	}
	try {
		C c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception & e) {
		throw (std::bad_cast());
	}
}

int	main() {
	A a;
	B b;
	C c;
	Base d;
	Base *random = generate();

	std::cout << "identification by pointer" << std::endl;
	identify(&a);
	identify(&b);
	identify(&c);
	identify(&d);
	identify(*random);

	std::cout << "\n\n";
	
	try {
		std::cout << "Identification by reference" << std::endl;
		identify(a);
		identify(b);
		identify(c);
		// identify(d);
		identify(random);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	delete random;

	return 0;
}