#ifndef _DOG_H_
#define _DOG_H_

#include "Animal.h"

class Dog: public Animal{
public:
	Dog();
	Dog(const Dog& dog);
	Dog& operator=(const Dog& dog);
	string getType() const;
	void makeSound() const;
	virtual ~Dog();
};


#endif
