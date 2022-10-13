#include "DiamondTrap.h"

int main()
{
	DiamondTrap diamondTrap("DiamondTrap");
	diamondTrap.attack("Target");
	diamondTrap.takeDamage(5);
	diamondTrap.beRepaired(5);
	diamondTrap.highFivesGuys();
	diamondTrap.guardGate();
	diamondTrap.whoAmI();
	return 0;
}