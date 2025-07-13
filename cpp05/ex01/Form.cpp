#include "Form.hpp"

void Form::beSigned(Bureaucrat &bureaucratForSign)
{
	if (bureaucratForSign.getGrade() <= this->_gradeToSign)
	{
		this->_isSigned = 1;
	}
	else
	{
		throw GradeTooLowException();
	}
}

Form::Form() : _name("Default Form"), _isSigned(0), _gradeToSign(1), _gradeToExecute(1)
{
};

Form::~Form()
{
};

Form::Form(const Form &src) : _name(src.getName()), _isSigned(src.getIsSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{

};


Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	this->_isSigned = 0;
	if (gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1)
		throw GradeTooHighException();
};

std::string Form::getName() const
{
	return this->_name;
};

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
};

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
};

bool Form::getIsSigned() const
{
	return this->_isSigned;
};

Form& Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return *this;
};

std::ostream& operator<<(std::ostream &out, Form &formToDisplay)
{
	out << "            Name : " << formToDisplay.getName() << std::endl;
	out << "       Is signed : " << formToDisplay.getIsSigned() << std::endl;
	out << "   Grade to sign : " << formToDisplay.getGradeToSign() << std::endl;
	out << "Grade to execute : " << formToDisplay.getGradeToExecute();
	return out;
}