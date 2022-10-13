
#include "ScavTrap.h"

int main()
{
	ScavTrap scavTrap("ScavTrap");
	scavTrap.attack("Target");
	scavTrap.takeDamage(5);
	scavTrap.beRepaired(5);
	scavTrap.guardGate();
	return 0;
}
