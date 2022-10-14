#include "Dog.h"
#include "Cat.h"
#include "WrongCat.h"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "Animal type is " << dog->getType() << " " << std::endl;
	std::cout << "Animal type is " <<cat->getType() << " " << std::endl;
	dog->makeSound(); //will output the cat sound!
	cat->makeSound();
	meta->makeSound();
	wrongCat->makeSound();

	delete meta;
	delete dog;
	delete cat;

	return 0;
}