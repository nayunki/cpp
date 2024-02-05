#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data {
private:
	int num;
	std::string str;
public:
	Data();
	Data(const Data & obj);
	Data & operator=(const Data &obj);
	~Data();
	const int & getNum() const;
	const std::string & getStr() const;
};

#endif