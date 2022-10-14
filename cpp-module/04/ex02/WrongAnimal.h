#ifndef _WRONGANIMAL_H_
#define _WRONGANIMAL_H_

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class WrongAnimal {

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& WrongAnimal);
	WrongAnimal& operator=(const WrongAnimal& WrongAnimal);
	const string& getType() const;
	void makeSound() const;
	virtual ~WrongAnimal();

protected:
	string type;
};


#endif
