#include "FragTrap.h"

FragTrap::FragTrap() {
	this->_name = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	cout << "FragTrap default constructor called" << endl;
}

FragTrap::FragTrap(const string& name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	cout << "FragTrap constructor called" << endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) {
	*this = fragTrap;
	cout << "FragTrap copy constructor called" << endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
	if(this == &fragTrap)
		return *this;
	this->_name = fragTrap._name;
	this->_hitPoints = fragTrap._hitPoints;
	this->_energyPoints = fragTrap._energyPoints;
	this->_attackDamage = fragTrap._attackDamage;
	return *this;
}

void FragTrap::highFivesGuys() {
	if(this->_energyPoints > 0 && this->_hitPoints > 0){
		cout << "FragTrap " << this->_name << " high fives" << endl;
		this->_energyPoints--;
	}
	else
		cout << "FragTrap " << this->_name << " has no " << (!this->_energyPoints ? "energy" : "hit points") << " left!" << endl;
}

FragTrap::~FragTrap() {
	cout << "FragTrap destructor called" << endl;
}