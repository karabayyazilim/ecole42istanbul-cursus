#include "Bureaucrat.h"
#include "Intern.h"

int main()
{
	try{
		Bureaucrat *a = new Bureaucrat("Bob", 10);
		Intern *z = new Intern();
		Form *b = z->makeForm("SomeRandomForm", "Clown");
		b = z->makeForm("PresidentialPardonForm", "Clown");
	}
	catch(std::exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}
