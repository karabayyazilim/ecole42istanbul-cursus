#include "Cure.h"

Cure::Cure() : AMateria("cure") {
	cout << "Cure constructor called" << endl;
}

Cure::Cure(const Cure& ice) : AMateria(ice) {
	cout << "Cure copy constructor called" << endl;
}

Cure& Cure::operator=(const Cure& cure) {
	if (this != &cure)
		return *this;
	this->_type = cure._type;
	cout << "Cure assignation operator called" << endl;
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	cout << "* heals " << target.getName() << "'s wounds *" << endl;
}

Cure::~Cure() {
	cout << "Cure destructor called" << endl;
}


