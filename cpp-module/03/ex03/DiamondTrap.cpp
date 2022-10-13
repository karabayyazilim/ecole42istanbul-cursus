#include "DiamondTrap.h"

DiamondTrap::DiamondTrap()
{
	this->_name = "DiamondTrap";
	ClapTrap::_name = this->_name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	cout << "DiamondTrap default constructor called" << endl;
}

DiamondTrap::DiamondTrap(const string &name): ClapTrap(name + "_clap_name") {
	_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	cout << "DiamondTrap constructor called" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) {
	*this = diamondTrap;
	cout << "DiamondTrap copy constructor called" << endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
	if(this == &diamondTrap)
		return *this;
	ClapTrap::_name = diamondTrap._name + "_clap_name";
	ScavTrap::_name = diamondTrap._name;
	FragTrap::_name = diamondTrap._name;
	_name = diamondTrap._name;
	this->_hitPoints = diamondTrap._hitPoints;
	this->_energyPoints = diamondTrap._energyPoints;
	this->_attackDamage = diamondTrap._attackDamage;
	return *this;
}

void DiamondTrap::whoAmI()
{
	cout << "DiamondTrap " << _name << " is actually ClapTrap " << ClapTrap::_name << endl;
}

DiamondTrap::~DiamondTrap()
{
	cout << "DiamondTrap destructor called" << endl;
}