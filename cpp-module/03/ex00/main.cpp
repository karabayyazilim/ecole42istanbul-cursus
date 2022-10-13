#include "ClapTrap.h"

int main()
{
	ClapTrap clapTrap("ClapTrap");
	clapTrap.attack("Target");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(5);
	return 0;
}