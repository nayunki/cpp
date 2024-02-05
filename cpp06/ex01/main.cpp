#include "Serializer.hpp"
#include "Data.hpp"

int	main() {
	Data d;

	std::cout << "Before Serializer" << std::endl;
	std::cout << "data address : " << &d << std::endl;
	std::cout << "data number : " << d.getNum() << ", string : " << d.getStr() << "\n\n";

	uintptr_t intermediate = Serializer::serialize(&d);
	Data * ret = Serializer::deserialze(intermediate);
	// Data * ret = Serializer::deserialze(Serializer::serialize(&d));

	std::cout << "After Serializer" << std::endl;
	std::cout << "data address : " << ret << std::endl;
	std::cout << "data number : " << ret->getNum() << ", string : " << ret->getStr() << "\n\n";

	return 0;
}