#include "AMateria.h"

AMateria::AMateria(const string &type) {
	this->_type = type;
}

string const& AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{

}