#ifndef _SHRUBBERYCREATIONFORM_H_
#define _SHRUBBERYCREATIONFORM_H_

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.h"
#include "Form.h"

class Bureaucrat;

class ShrubberyCreationForm : public Form {
private:
	const std::string _target;

	ShrubberyCreationForm(void);

public:
	ShrubberyCreationForm(std::string target);

	ShrubberyCreationForm(ShrubberyCreationForm &src);

	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	void execute(Bureaucrat const &executor) const;

	std::string getTarget(void) const;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *a);

#endif
