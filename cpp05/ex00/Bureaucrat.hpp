#include <iostream>
#include <string>
#include <exception>
#include <ostream>

class Bureaucrat
{
	private:	
		const std::string	_name;
		int					_grade;

	public:
    	Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();
		Bureaucrat& operator= (const Bureaucrat& rhs);
		
		std::string	getName() const;
		int			getGrade() const;

		void		setGrade(int grade);
		
		void		incrementGrade();
		void		decrementGrade();

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat &BureaucratToDisplay);