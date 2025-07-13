#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <ostream>


class Form;

class Bureaucrat
{
	public:
    	Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator= (const Bureaucrat& rhs);
		~Bureaucrat();

		std::string getName() const;
		void setGrade(int grade);
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(Form &formToSign);

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

	private:	
		const std::string	_name;
		int					_grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &BureaucratToDisplay);

#endif