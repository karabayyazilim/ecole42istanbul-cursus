#ifndef _SCAVTRAP_H_
#define _SCAVTRAP_H_

#include <iostream>
#include "ClapTrap.h"

using std::cout;
using std::endl;
using std::string;

class ScavTrap : public ClapTrap
{
	public:
	ScavTrap();
	ScavTrap(const string &name);
	ScavTrap(const ScavTrap &scavTrap);
	ScavTrap &operator=(const ScavTrap &scavTrap);

	void guardGate();
	void attack(const string &target);

	~ScavTrap();
};


#endif
