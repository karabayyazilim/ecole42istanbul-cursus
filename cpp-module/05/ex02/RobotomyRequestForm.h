#ifndef _ROBOTOMYREQUESTFORM_H_
#define _ROBOTOMYREQUESTFORM_H_

#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.h"
#include "Form.h"

// classes

class Bureaucrat;

class From;

class RobotomyRequestForm : public Form {
private:
	const std::string _target;

	RobotomyRequestForm(void);

public:
	RobotomyRequestForm(std::string target);

	RobotomyRequestForm(RobotomyRequestForm &src);

	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

	void execute(Bureaucrat const &executor) const;

	std::string getTarget(void) const;

	~RobotomyRequestForm();
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *a);

#endif
