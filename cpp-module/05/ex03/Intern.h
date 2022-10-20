#ifndef _INTERN_H_
#define _INTERN_H_

#include <string>
#include <iostream>
#include "Form.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"


class Intern {
public:
	Intern();

	Intern(const Intern &src);

	~Intern();

	Intern &operator=(const Intern &src);

	Form *makeForm(const std::string form, const std::string target);

};

#endif
