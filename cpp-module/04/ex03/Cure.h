#ifndef _CURE_H_
#define _CURE_H_

#include "AMateria.h"

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure& cure);
	Cure& operator=(const Cure& cure);
	AMateria* clone() const;
	void use(ICharacter& target);
	virtual ~Cure();

};


#endif
