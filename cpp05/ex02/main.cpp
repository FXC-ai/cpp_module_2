#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

	std::cout << "----------------- ShrubberyCreationForm -----------------" << std::endl;

	Bureaucrat				alain("Alain", 1);
	ShrubberyCreationForm	covidLaw("Fribourg");

	alain.executeForm(covidLaw);
	alain.signForm(covidLaw);
	alain.signForm(covidLaw);
	alain.executeForm(covidLaw);

	std::cout << std::endl;

	std::cout << "----------------- RobotomyRequestForm -----------------" << std::endl;

	Bureaucrat				sutter("Sutter", 4);
	RobotomyRequestForm		robotomyForm("Renens");

	sutter.signForm(robotomyForm);
	sutter.executeForm(robotomyForm);

	std::cout << std::endl;

	std::cout << "----------------- RobotomyRequestForm -----------------" << std::endl;

	Bureaucrat				beeblebrox("Zaphod Beeblebrox", 2);

	PresidentialPardonForm begYourPardon("Arthur Dent");

	beeblebrox.executeForm(begYourPardon);
	beeblebrox.signForm(begYourPardon);

	beeblebrox.executeForm(begYourPardon);



	return 0;
}