

#include "WrongCat.h"

WrongCat::WrongCat() {
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wrongCat) {
	*this = wrongCat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat) {
	this->type = wrongCat.type;
	return *this;
}

void WrongCat::makeSound() const {
	cout << "Wrong Cat miyavvvvvv" << endl;
}

WrongCat::~WrongCat() {
	cout << "Wrong Cat destructor called" << endl;
}