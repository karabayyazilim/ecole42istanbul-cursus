#ifndef _ICE_H_
#define _ICE_H_

#include "AMateria.h"

class Ice: public AMateria {
public:
	Ice();
	Ice(const Ice &ice);
	Ice &operator=(const Ice &ice);
	AMateria *clone() const;
	void use(ICharacter &target);
	virtual ~Ice();

};


#endif
