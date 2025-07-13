#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default name"), _grade(150)
{
};

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	this->setGrade(grade);
};

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()), _grade(src.getGrade())
{
};

Bureaucrat::~Bureaucrat() 
{
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

void Bureaucrat::incrementGrade() 
{
	if (this->_grade - 1 < 1) 
	{
		throw GradeTooHighException();
	}
	this->_grade--;
}

void Bureaucrat::decrementGrade() 
{
	if (this->_grade + 1 > 150)
	{
		throw GradeTooLowException();
	}
	this->_grade++;
}

void	Bureaucrat::signForm(AForm &formToSign)
{
	try
	{
		formToSign.beSigned(*this);
		std::cout << this->getName() << " signed " << formToSign.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << formToSign.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " failed to execute " << form.getName() << std::endl;
		std::cerr << e.what() << std::endl;
	}
	
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &BureaucratToDisplay)
{
	os << BureaucratToDisplay.getName() << ", bureaucrat grade " << BureaucratToDisplay.getGrade();
	return os;
}