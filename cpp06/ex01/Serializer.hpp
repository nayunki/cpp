#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <cstdint>

struct Data {
	int num;
	std::string str;
};

class Serializer {
private:
	Serializer();
	Serializer(const Serializer & obj);
	Serializer & operator=(const Serializer &obj);
public:
	~Serializer();
	static uintptr_t serialize(Data * ptr);
	static Data *deserialze(uintptr_t raw);
};

#endif