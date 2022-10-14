#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Animal {

public:
	Animal& operator=(const Animal& animal);
	const string& getType() const;
	virtual void makeSound() const;
	virtual ~Animal();

protected:
	Animal();
	Animal(const Animal& animal);
	string type;
};


#endif
