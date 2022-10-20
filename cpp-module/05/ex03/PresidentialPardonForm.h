#ifndef _PRESIDENTIALPARDONFORM_H_
#define _PRESIDENTIALPARDONFORM_H_


#include <string>
#include <iostream>
#include "Bureaucrat.h"
#include "Form.h"


class PresidentialPardonForm : public Form {
private:
	const std::string _target;

	PresidentialPardonForm(void);

public:
	PresidentialPardonForm(std::string target);

	PresidentialPardonForm(PresidentialPardonForm &src);

	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

	void execute(Bureaucrat const &executor) const;

	std::string getTarget(void) const;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *a);

#endif
