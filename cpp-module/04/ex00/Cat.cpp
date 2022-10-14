#include "Cat.h"

Cat::Cat() {
	this->type = "Cat";
	cout << "Cat constructor called" << endl;
}

Cat::Cat(const Cat& cat) {
	*this = cat;
	cout << "Cat copy constructor called" << endl;
}

Cat& Cat::operator=(const Cat& cat) {
	if (this != &cat)
		return *this;
	this->type = cat.type;
	cout << "Cat assignation operator called" << endl;
	return *this;
}

void Cat::makeSound() const {
	cout << "Cat miyavvvvv" << endl;
}

Cat::~Cat() {
	cout << "Cat destructor called" << endl;
}
