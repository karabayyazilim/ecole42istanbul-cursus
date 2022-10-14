#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Animal {

public:
	Animal();
	Animal(const Animal& animal);
	Animal& operator=(const Animal& animal);
	const string& getType() const;
	virtual void makeSound() const;
	virtual ~Animal();

protected:
	string type;
};


#endif
