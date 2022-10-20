#ifndef _CONVERT_H_
#define _CONVERT_H_

#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::string;


class Convert {

public:
	Convert();
	Convert(const Convert &copy);
	Convert &operator=(const Convert &copy);
	void run(const string& str);
	~Convert();
private:

	void toChar(const string& str);
	void toInt(const string& str);
	void toFloat(const string& str);
	void toDouble(const string& str);
	void printNumber(const char c, char type);

	bool isNan(const string& str);
	const string toUpperCase(const string& str);
};


#endif
