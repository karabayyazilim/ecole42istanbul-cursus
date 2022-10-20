#include "Bureaucrat.h"
#include "Form.h"

int main()
{
	try{
		Bureaucrat bureaucrat("Bob", 10);
		Form form("Form", 5, 5);
		bureaucrat.signForm(form);

		bureaucrat.increment(10);

	}
	catch(std::exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}
