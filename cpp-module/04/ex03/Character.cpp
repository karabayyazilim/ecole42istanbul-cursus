#include "Character.h"

#include <iostream>

Character::Character(const string& name) {
	this->_name = name;
	this->_count = 0;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	cout << "Character constructor called" << endl;
}

Character::Character(const Character &character) {
	*this = character;
	cout << "Character copy constructor called" << endl;
}

Character &Character::operator=(const Character &character) {
	if (this != &character)
		return *this;
	cout << "Character assignation operator called" << endl;
	return *this;
}

std::string const& Character::getName() const
{
	return this->_name;
}


void Character::equip(AMateria *materia) {
	if (!materia)
		return;
	for (int i = 0; i < 4; ++i) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = materia;
			this->_count++;
			break;
		}
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= _count || !_inventory[idx])
		return;
	this->_inventory[idx]->use(target);
}

void Character::unequip(int idx)
{
	if (idx > _count || !_inventory[idx])
		return;
	this->_inventory[idx] = NULL;
}

Character::~Character() {
	cout << "Character destructor called" << endl;
}