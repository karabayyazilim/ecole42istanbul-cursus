#ifndef _BRAIN_H_
#define _BRAIN_H_

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Brain {
public:
	Brain();
	Brain(const Brain &brain);
	Brain &operator=(const Brain &brain);

	virtual ~Brain();

private:
	string ideas[100];
};


#endif
