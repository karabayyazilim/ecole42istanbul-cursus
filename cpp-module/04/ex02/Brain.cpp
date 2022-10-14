

#include "Brain.h"

Brain::Brain() {
	cout << "Brain constructor called" << endl;
}

Brain::Brain(const Brain &brain) {
	*this = brain;
	cout << "Brain copy constructor called" << endl;
}

Brain &Brain::operator=(const Brain &brain) {
	if (this != &brain)
		return *this;
	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = brain.ideas[i];
	}
	cout << "Brain assignation operator called" << endl;
	return *this;
}

Brain::~Brain() {
	cout << "Brain destructor called" << endl;
}
