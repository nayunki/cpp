#include "Serializer.hpp"

int	main() {
	Data d;
	d.num = 1;
	d.str = "hi";

	std::cout << "Before Serializer" << std::endl;
	std::cout << "data address : " << &d << std::endl;
	std::cout << "data number : " << d.num << ", string : " << d.str << "\n\n";

	uintptr_t intermediate = Serializer::serialize(&d);
	Data * ret = Serializer::deserialze(intermediate);
	// Data * ret = Serializer::deserialze(Serializer::serialize(&d));

	std::cout << "After Serializer" << std::endl;
	std::cout << "data address : " << ret << std::endl;
	std::cout << "data number : " << ret->num << ", string : " << ret->str << "\n\n";

	return 0;
}