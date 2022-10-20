#include "Bureaucrat.h"

int main()
{
	try{
		Bureaucrat bureaucrat("Bob", 10);
		cout << bureaucrat;

		Bureaucrat bureaucrat2("bob",0);
	}
	catch(std::exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}
