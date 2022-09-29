
#ifndef _HUMANA_H_
#define _HUMANA_H_

#include <iostream>
#include <string>
#include "Weapon.h"

using std::string;
using std::cout;
using std::endl;

class HumanA {
public:
    HumanA(const string& name, const Weapon& weapon);
    void attack();
private:
 const Weapon* _weapon;
 string _name;
};


#endif
