#include "Dog.h"

Dog::Dog() {
	this->type = "Dog";
	cout << "Dog constructor called" << endl;
}

Dog::Dog(const Dog& dog) {
	*this = dog;
	cout << "Dog copy constructor called" << endl;
}

Dog& Dog::operator=(const Dog& dog) {
	if (this != &dog)
		return *this;
	this->type = dog.type;
	cout << "Dog assignation operator called" << endl;
	return *this;
}

void Dog::makeSound() const {
	cout << "Dog hav hav hav" << endl;
}

Dog::~Dog() {
	cout << "Dog destructor called" << endl;
}