#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm () : AForm("PresidentialPardonForm", 25, 5), _target("default_target")
{
};

PresidentialPardonForm::PresidentialPardonForm (std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src.getTarget())
{
};

PresidentialPardonForm::~PresidentialPardonForm()
{

};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	AForm::operator=(rhs);
	return *this;
};

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{

	if (executor.getGrade() <= this->getGradeToExecute())
	{
		if (this->getIsSigned() == 1)
		{
			std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		}
		else
		{
			throw FormNotSignedException();
		}
	}
	else
	{
		throw GradeTooLowException();
	}
};