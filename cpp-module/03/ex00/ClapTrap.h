#ifndef _CLAPTRAP_H_
#define _CLAPTRAP_H_

#include <iostream>

using std::cout;
using std::endl;
using std::string;


class ClapTrap {

public:
	ClapTrap();
	ClapTrap(const string& name);
	ClapTrap(const ClapTrap& clapTrap);
	ClapTrap& operator=(const ClapTrap& clapTrap);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	~ClapTrap();


private:
	string _name;
	int	_hitPoints;
	int _energyPoints;
	int	_attackDamage;


};


#endif
