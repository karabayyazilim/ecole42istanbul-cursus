
#include "HumanB.h"

HumanB::HumanB(const string &name) {
    this->_name = name;
    this->_weapon = NULL;
}

void HumanB::setWeapon(const Weapon &weapon) {
    this->_weapon = &weapon;
}

void HumanB::attack() const {
    if(this->_weapon == NULL)
        return;
    cout << _name << " attacks with their " << _weapon->getType() << endl;
}