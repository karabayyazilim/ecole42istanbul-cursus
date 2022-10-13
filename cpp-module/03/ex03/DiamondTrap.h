#ifndef _DIAMONDTRAP_H_
#define _DIAMONDTRAP_H_

#include <iostream>
#include "ScavTrap.h"
#include "FragTrap.h"

using std::cout;
using std::endl;
using std::string;

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(const string &name);
	DiamondTrap(const DiamondTrap &diamondTrap);
	DiamondTrap &operator=(const DiamondTrap &diamondTrap);

	void whoAmI();

	~DiamondTrap();

private:
	string _name;
};


#endif
