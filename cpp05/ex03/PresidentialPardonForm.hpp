#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <fstream>

class PresidentialPardonForm : public AForm
{
	private :
		const std::string _target;

	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		std::string getTarget() const;

		virtual void execute(Bureaucrat const & executor) const;
};

#endif