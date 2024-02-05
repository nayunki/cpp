#include "Base.hpp"

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
	
	std::cout << "Identification by reference" << std::endl;
	identify(a);
	// identify(b);
	// identify(c);
	// identify(d);
	identify(random);
	
	delete random;

	return 0;
}