#include "ShrubberyCreationForm.h"


ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src): Form("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor called to copy " << src.getName() <<
			  " into " << this->getName() << std::endl;
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getGradeToExecute())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->isSigned() == false)
		throw (Form::FormNotSignedException());
	else
	{
		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());

		outfile << 		"                                @@@@@@@@      @@@@@  .@@@@@@@                   \n" <<
				"                             .@@@@@@@,        @@,    .@@@@@@@                   \n" <<
				"                           @@@@@@@@                  /@@@@@@@                   \n" <<
				"                        *@@@@@@@.                  @@@@@@@@					 \n" <<
				"						@@@@@@@                   @@@@@@@@					     \n" <<
				"                      @@@@@@@@                  #@@@@@@@                        \n" <<
				"                   (@@@@@@@///////////////*   @@@@@@@&                          \n" <<
				"                   #@@@@@@@@@@@@@@@@@@@@@@#   @@@@@@@%     @@                   \n" <<
				"                   #@@@@@@@@@@@@@@@@@@@@@@#   @@@@@@@%  @@@@@                   \n" <<
				"                                   @@@@@@@#   #######(#######                   \n" <<
				"                                   @@@@@@@#                                     \n" <<
				"                                   @@@@@@@#                         				";

		outfile.close();
	}
}

// Getter
std::string	ShrubberyCreationForm::getTarget(void)const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
	o << "Form " << a->getName() <<
	  ":\n\tsign-grade:\t" << a->getGradeToSign() <<
	  "\n\texec-grade:\t" << a->getGradeToExecute() <<
	  "\n\tis signed:\t" << a->isSigned() <<
	  std::endl;
	return (o);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Deconstructor " << this->getName() << " called" << std::endl;
}
