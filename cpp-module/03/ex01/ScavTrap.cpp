
#include "ScavTrap.h"

ScavTrap::ScavTrap() {
	this->_name = "ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	cout << "ScavTrap default constructor called" << endl;
}

ScavTrap::ScavTrap(const string &name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	cout << "ScavTrap constructor called" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
	*this = scavTrap;
	cout << "ScavTrap copy constructor called" << endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
	if(this == &scavTrap)
		return *this;
	this->_name = scavTrap._name;
	this->_hitPoints = scavTrap._hitPoints;
	this->_energyPoints = scavTrap._energyPoints;
	this->_attackDamage = scavTrap._attackDamage;
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if(this->_energyPoints > 0 && this->_hitPoints > 0){
		cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << endl;
		this->_energyPoints--;
	}
	else
		cout << "ScavTrap " << this->_name << " has no " << (!this->_energyPoints ? "energy" : "hit points") << " left!" << endl;
}

void ScavTrap::guardGate() {
	if(this->_energyPoints > 0 && this->_hitPoints > 0){
		cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << endl;
		this->_energyPoints--;
	}
	else
		cout << "ScavTrap " << this->_name << " has no " << (!this->_energyPoints ? "energy" : "hit points") << " left!" << endl;
}

ScavTrap::~ScavTrap() {
	cout << "ScavTrap destructor called" << endl;
}