
#include "HumanA.h"

HumanA::HumanA(const string &name, const Weapon &weapon) {
    this->_name = name;
    this->_weapon = &weapon;
}

void HumanA::attack() {
    if(this->_weapon == NULL)
        return;
    cout << _name << " attacks with their " << _weapon->getType() << endl;
}