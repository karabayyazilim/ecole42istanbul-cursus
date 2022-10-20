#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(const string& name, int grade) : _name(name) {
	setGrade(grade);
	cout << "Bureaucrat default constructor called" << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : _name(bureaucrat._name) {
	*this = bureaucrat;
	cout << "Bureaucrat copy constructor called" << endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat){
	if(this == &bureaucrat) {
		return *this;
	}
	setGrade(bureaucrat._grade);
	return *this;
}

const string& Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::setGrade(int grade) {
	if(grade < 1) {
		throw GradeTooHighException();
	}
	else if(grade > 150) {
		throw GradeTooLowException();
	}
	else {
		this->_grade = grade;
	}
}

Bureaucrat::~Bureaucrat() {
	cout << "Bureaucrat destructor called" << endl;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", grade " << bureaucrat.getGrade() << "." << endl;
	return (out);
}


