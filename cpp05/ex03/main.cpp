#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	
	Intern		james;
	Bureaucrat	parmelin("Guy Parmelin", 1);

	std::cout << "------------------ Test Robotomy ------------------" << std::endl;
	AForm *RobotomyRequestForm0 = james.makeForm("RobotomyRequestForm","42 Lausanne");
	parmelin.signForm(*RobotomyRequestForm0);
	parmelin.executeForm(*RobotomyRequestForm0);
	delete RobotomyRequestForm0;
	std::cout << std::endl;

	std::cout << "------------------ Test Shrubbery ------------------" << std::endl;
	AForm *ShrubberyCreationForm0 = james.makeForm("ShrubberyCreationForm","Saxon");
	parmelin.signForm(*ShrubberyCreationForm0);
	parmelin.executeForm(*ShrubberyCreationForm0);
	delete ShrubberyCreationForm0;
	std::cout << std::endl;


	std::cout << "------------------ Test Presidential Pardon ------------------" << std::endl;
	AForm *PresidentialPardonForm0 = james.makeForm("PresidentialPardonForm","Ford Perfect");
	parmelin.signForm(*PresidentialPardonForm0);
	parmelin.executeForm(*PresidentialPardonForm0);
	delete PresidentialPardonForm0;
	std::cout << std::endl;	

	std::cout << "------------------ Test False Form ------------------" << std::endl;
	AForm *FalseForm0 = james.makeForm("FalseForm","Bale");
	(void) FalseForm0;
	std::cout << std::endl;	

	return 0;
}