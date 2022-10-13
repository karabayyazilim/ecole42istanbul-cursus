#include "ClapTrap.h"

ClapTrap::ClapTrap() {
	this->_name = "ClapTrap";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	cout << "ClapTrap default constructor called" << endl;
}

ClapTrap::ClapTrap(const string &name) {
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	cout << "Claptrap constructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	*this = clapTrap;
	cout << "Claptrap copy constructor called" << endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
	if(this == &clapTrap)
		return *this;
	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_energyPoints = clapTrap._energyPoints;
	this->_attackDamage = clapTrap._attackDamage;
	return *this;
}

void ClapTrap::attack(const string& target) {
	if(this->_energyPoints > 0 && this->_hitPoints > 0){
		cout << "Claptrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << endl;
		this->_energyPoints--;
	}
	else
		cout << "Claptrap " << this->_name << " has no " << (!this->_energyPoints ? "energy" : "hit points") << " left!" << endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if(this->_hitPoints > 0 && this->_energyPoints > 0){
		cout << "Claptrap " << this->_name << " takes " << amount << " points of damage!" << endl;
		this->_hitPoints -= amount;
	}
	else
		cout << "Claptrap " << this->_name << " has no " << (!this->_energyPoints ? "energy" : "hit points") << " left!" << endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if(this->_hitPoints > 0 && this->_energyPoints > 0){
		cout << "Claptrap " << this->_name << " is repaired by " << amount << " points!" << endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		cout << "Claptrap " << this->_name << " has no " << (!this->_energyPoints ? "energy" : "hit points") << " left!" << endl;
}

ClapTrap::~ClapTrap() {
	cout << "Claptrap destructor called" << endl;
}