#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"

int main()
{
	try{
		Bureaucrat bureaucrat("Bob", 1);

		ShrubberyCreationForm form("Form");
		bureaucrat.signForm(form);
		form.execute(bureaucrat);
	}
	catch(std::exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}
