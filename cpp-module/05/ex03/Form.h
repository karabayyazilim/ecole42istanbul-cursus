#ifndef _FORM_H_
#define _FORM_H_

#include <iostream>
#include "Bureaucrat.h"


using std::string;
using std::cout;
using std::endl;

class Form {
public:
	Form();

	Form(const string &name, int gradeToSign, int gradeToExecute);

	Form(const Form &form);

	Form &operator=(const Form &form);

	bool isSigned() const;

	string getName() const;

	int getGradeToSign() const;

	int getGradeToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat) const;

	virtual ~Form();

private:
	mutable bool _isSigned;
	const string _name;
	const int _gradeToSign;
	const int _gradeToExecute;

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw() {
			return "Grade too high";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw() {
			return "Grade too low";
		}
	};

protected:
	class FormNotSignedException : public std::exception {
	public:
		const char *what() const throw() {
			return "Form not signed";
		}
	};
};


#endif
