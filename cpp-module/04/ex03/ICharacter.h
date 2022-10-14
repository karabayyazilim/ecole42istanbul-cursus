#ifndef _ICHARACTER_H_
#define _ICHARACTER_H_

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual std::string const& getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif
