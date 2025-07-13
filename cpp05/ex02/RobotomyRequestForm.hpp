#ifndef ROBOTOMY_CREATION_FORM_HPP
#define ROBOTOMY_CREATION_FORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <fstream>

class RobotomyRequestForm : public AForm
{
	private :
		const std::string _target;

	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
		std::string getTarget() const;

		virtual void execute(Bureaucrat const & executor) const;
};


#endif