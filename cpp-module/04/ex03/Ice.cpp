#include "Ice.h"

Ice::Ice() : AMateria("ice") {
	cout << "Ice constructor called" << endl;
}

Ice::Ice(const Ice& ice) : AMateria(ice) {
	cout << "Ice copy constructor called" << endl;
}

Ice& Ice::operator=(const Ice& ice) {
	if (this != &ice)
		return *this;
	this->_type = ice._type;
	cout << "Ice assignation operator called" << endl;
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}

Ice::~Ice() {
	cout << "Ice destructor called" << endl;
}


