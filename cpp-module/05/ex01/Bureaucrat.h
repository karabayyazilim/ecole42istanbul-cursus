
#ifndef _BUREAUCRAT_H_
#define _BUREAUCRAT_H_

#include <iostream>

class Form;

using std::cout;
using std::endl;
using std::string;

class Bureaucrat {

public:
	Bureaucrat(const string &name, int grade);
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat &operator=(const Bureaucrat &bureaucrat);

	void increment();
	void increment(int quantity);
	void decrement();
	void decrement(int quantity);

	void signForm(const Form &form) const;

	const string &getName() const;
	int getGrade() const;

	~Bureaucrat();

private:
	const string _name;
	int _grade;

	void setGrade(int grade);

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

};


std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);


#endif
