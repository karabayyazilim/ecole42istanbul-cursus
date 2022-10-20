#include "Form.h"

Form::Form() : _isSigned(false), _name("default"), _gradeToSign(150), _gradeToExecute(150) {
	cout << "Form Default Constructor" << endl;
}

Form::Form(const string &name, int gradeToSign, int gradeToExecute) : _isSigned(false), _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	const int i = this->getGradeToSign();
	const int j = this->getGradeToExecute();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
	cout << "Form Constructor called" << endl;
}

Form::Form(const Form &form) : _isSigned(form._isSigned), _name(form._name), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute) {
	*this = form;
	cout << "Form Copy Constructor" << endl;
}

Form &Form::operator=(const Form &form) {
	if (this == &form)
		return *this;
	cout << "Form Assignment Operator" << endl;
	return *this;
}

bool Form::isSigned() const {
	return _isSigned;
}

string Form::getName() const {
	return _name;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) const {
	if (bureaucrat.getGrade() <= _gradeToSign) {
		this->_isSigned = true;
		cout << bureaucrat.getName() << " signed " << _name << endl;
	} else {
		cout << bureaucrat.getName() << " couldn’t sign " << _name << " because ";
		throw GradeTooLowException();
	}
}

Form::~Form() {
	cout << "Form Destructor" << endl;
}
