#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <ostream>


class Bureaucrat;

class AForm
{
	private :
		const std::string	_name;
		bool 				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public :
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &src);
		virtual ~AForm();

		AForm& operator=(const AForm &rhs);

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;

		void beSigned(Bureaucrat &bureaucratForSign);

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Grade too High !!!";
			}
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Grade too Low !!!";
			}
		};

		class FormNotSignedException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Form not signed !!!";
			}
		};

		class FormAlreadySignedException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Form already signed !!!";
			}
		};

		virtual void execute(Bureaucrat const & executor) const = 0; 
};

std::ostream& operator<<(std::ostream &out, AForm &formToDisplay);

#endif