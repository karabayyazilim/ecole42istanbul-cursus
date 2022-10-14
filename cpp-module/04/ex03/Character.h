#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "AMateria.h"
#include "ICharacter.h"

class Character : public ICharacter {
public:
	Character(const string& name);
	Character(const Character &character);
	Character &operator=(const Character &character);


	std::string const& getName() const;
	void equip(AMateria* materia);
	void unequip(int idx);
	void use(int idx, ICharacter& target);


	virtual ~Character();

private:
	AMateria *_inventory[4];
	string _name;
	int _count;
};


#endif
