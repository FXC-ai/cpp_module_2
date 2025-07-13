#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <ostream>


class Bureaucrat;

class Form
{
	private :
		const std::string	_name;
		bool 				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public :
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &src);
		Form& operator=(const Form &rhs);
		~Form();

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
};

std::ostream& operator<<(std::ostream &out, Form &formToDisplay);

#endif