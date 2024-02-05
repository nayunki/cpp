#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

class Data;

class Serializer {
private:
	Serializer();
	Serializer(const Serializer & obj);
public:
	Serializer & operator=(const Serializer &obj);
	~Serializer();
	static uintptr_t serialize(Data * ptr);
	static Data *deserialze(uintptr_t raw);
};

#endif