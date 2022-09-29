#ifndef _WEAPON_H_
#define _WEAPON_H_

#include <iostream>

using std::string;

class Weapon
{
public:
    Weapon();
    Weapon(const string& type);

    const string& getType() const;
    void setType(const string& type);

private:
    string _type;
};

#endif
