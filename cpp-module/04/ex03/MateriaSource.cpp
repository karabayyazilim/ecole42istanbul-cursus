#include "MateriaSource.h"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	this->_count = 0;
	cout << "MateriaSource created" << endl;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource) {
	*this = materiaSource;
	cout << "MateriaSource copy constructor called" << endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiaSource) {
	if (this != &materiaSource)
		return *this;
	cout << "MateriaSource assignation operator called" << endl;
	return *this;
}


void MateriaSource::learnMateria(AMateria* materia) {
	if (this->_count == 4 || !materia)
		return;
	this->_materia[this->_count] = materia;
	this->_count++;
}

AMateria* MateriaSource::createMateria(string const & type) {
	for (int i = 0; i < this->_count; i++) {
		if (this->_materia[i]->getType() == type)
			return this->_materia[i]->clone();
	}
	return NULL;
}

MateriaSource::~MateriaSource()
{
	cout << "MaterialSource destructor called" << endl;
}