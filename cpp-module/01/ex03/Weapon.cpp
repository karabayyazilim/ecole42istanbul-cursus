#include "Weapon.h"

Weapon::Weapon() : _type("Undefined"){}

Weapon::Weapon(const string &type) {
    this->_type = type;
}

const std::string &Weapon::getType() const{
    return _type;
}

void Weapon::setType(const std::string &type) {
    this->_type = type;
}