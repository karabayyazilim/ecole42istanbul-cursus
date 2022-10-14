

#include "Animal.h"

Animal::Animal() {
	this->type = "Animal";
	cout << "Animal constructor called" << endl;

}

Animal::Animal(const Animal& animal) {
	*this = animal;
	cout << "Animal copy constructor called" << endl;
}

Animal& Animal::operator=(const Animal& animal) {
	if (this != &animal)
		return *this;
	this->type = animal.type;
	cout << "Animal assignation operator called" << endl;
	return *this;
}

const string& Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {

}

Animal::~Animal() {
	cout << "Animal destructor called" << endl;
}