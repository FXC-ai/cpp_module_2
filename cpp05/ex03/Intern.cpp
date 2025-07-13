#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){};

Intern::Intern(const Intern &src)
{
	(void) src;
};

Intern::~Intern(){};

Intern& Intern::operator=(const Intern &rhs)
{
	(void) rhs;
	return *this;
}

AForm* Intern::makeForm(const std::string formName, const std::string target)
{
	const std::string tab[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int id_form;
	int i;
	AForm* tabForms[3];
	
	id_form = -1;
	i = 0;
	tabForms[0] = new ShrubberyCreationForm(target); 
	tabForms[1] = new RobotomyRequestForm(target); 
	tabForms[2] = new PresidentialPardonForm(target); 

	while (i < 3)
	{
		if (tab[i].compare(formName) != 0)
			delete tabForms[i];
		else
			id_form = i;
		i++;
	}

	if (id_form != -1)
	{
		std::cout << "Intern creates " << formName << std::endl;
		return tabForms[id_form];
	}
	std::cout << "Intern can not creates " << formName << std::endl;
	return nullptr;
}