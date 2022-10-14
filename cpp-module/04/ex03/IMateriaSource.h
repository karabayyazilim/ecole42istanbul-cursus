#ifndef _IMATERIASOURCE_H_
#define _IMATERIASOURCE_H_

#include "AMateria.h"

class IMateriaSource {
public:
	virtual ~IMateriaSource() {}

	virtual void learnMateria(AMateria *) = 0;

	virtual AMateria *createMateria(std::string const &type) = 0;
};


#endif
