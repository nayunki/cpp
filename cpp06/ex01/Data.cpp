#include "Data.hpp"

Data::Data() {
	num = 1;
	str = "hi";
}

Data & Data::operator=(const Data &obj) {
	this->num = obj.getNum();
	this->str = obj.getStr();
	return (*this);
}

Data::Data(const Data & obj) {
	*this = obj;
}

Data::~Data() {
}

const int & Data::getNum() const {
	return (this->num);
}

const std::string & Data::getStr() const {
	return (this->str);
}