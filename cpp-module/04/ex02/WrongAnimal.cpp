#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
	cout << "Wrong Animal constructor called" << endl;

}

WrongAnimal::WrongAnimal(const WrongAnimal& WrongAnimal) {
	*this = WrongAnimal;
	cout << "Wrong Animal copy constructor called" << endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& WrongAnimal) {
	if (this != &WrongAnimal)
		return *this;
	this->type = WrongAnimal.type;
	cout << "Wrong Animal assignation operator called" << endl;
	return *this;
}

const string& WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	cout << "Wrong Animal sound" << endl;
}

WrongAnimal::~WrongAnimal() {
	cout << "Wrong Animal destructor called" << endl;
}