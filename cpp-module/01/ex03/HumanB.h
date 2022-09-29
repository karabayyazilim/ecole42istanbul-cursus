
#ifndef _HUMANB_H_
#define _HUMANB_H_

#include <iostream>
#include "Weapon.h"

using std::string;
using std::cout;
using std::endl;

class HumanB {
public:
    HumanB(const string& name);
    void setWeapon(const Weapon& weapon);
    void attack() const;
private:
 const Weapon* _weapon;
 string _name;
};


#endif
