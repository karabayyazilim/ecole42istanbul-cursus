#include <iostream>
#include "FragTrap.h"

int main()
{
	FragTrap fragTrap("FragTrap");
	fragTrap.attack("Target");
	fragTrap.takeDamage(5);
	fragTrap.beRepaired(5);
	fragTrap.highFivesGuys();
	return 0;
}