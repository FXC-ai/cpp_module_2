#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) , _target("default_target")
{
};

RobotomyRequestForm::RobotomyRequestForm (std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src.getTarget())
{
};

RobotomyRequestForm::~RobotomyRequestForm()
{
};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	AForm::operator=(rhs);
	return *this;
};

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{

	if (executor.getGrade() <= this->getGradeToExecute())
	{

		if (this->getIsSigned() == 1)
		{
			srand(time(0));
			if (rand() % 2)
			{
				std::cout << "Brrrr... Brrrr... Brrrr... " << this->getTarget() << " has been robotomized." << std::endl;
			}
			else
			{
				std::cout << "The robotomy failed." << std::endl;
			}
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