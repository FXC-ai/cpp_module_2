#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private :
		const std::string _target;

	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		std::string getTarget() const;

		virtual void execute(Bureaucrat const & executor) const;
};


#endif