#ifndef _FRAGTRAP_H_
#define _FRAGTRAP_H_

#include <iostream>
#include "ClapTrap.h"
#include "ScavTrap.h"

using std::cout;
using std::endl;
using std::string;

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const string &name);
	FragTrap(const FragTrap &fragTrap);
	FragTrap &operator=(const FragTrap &fragTrap);

	void highFivesGuys();

	~FragTrap();
};


#endif
