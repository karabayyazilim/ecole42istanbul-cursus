#ifndef _AMATERIA_H_
#define _AMATERIA_H_

#include "ICharacter.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class AMateria {
protected:
	string _type;

public:
	AMateria(std::string const &type);

	std::string const &getType() const;
	virtual AMateria *clone() const = 0;

	virtual void use(ICharacter &target);
};

#endif
