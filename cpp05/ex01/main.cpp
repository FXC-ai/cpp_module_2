#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "--------- Tests d'instanciations --------" << std::endl;

	Form	RandomLaw;

	std::cout << RandomLaw << std::endl;

	Form	SecondRandomLaw(RandomLaw);

	std::cout << SecondRandomLaw << std::endl;

	std::cout << std::endl;


	std::cout << "--------- Test 0 --------" << std::endl;
	try
	{
		Form	buildAuth("Area Build Authorization", -1500, -1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form	buildAuth("Area Build Authorization", 1500, 5000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "--------- Test 1 --------" << std::endl;
	try
	{
		Bureaucrat	amherd("Amherd", 50);
		Form		water("Water Quality Preservation", 50, 25);
		std::cout << amherd << std::endl;
		std::cout << std::endl;
		std::cout << water << std::endl;
		std::cout << std::endl;
		amherd.signForm(water);
		std::cout << std::endl;
		std::cout << water << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "--------- Test 2 --------" << std::endl;

	Bureaucrat	keller("Keller", 65);
	Form		autoDrive("Authorising Autonomous Driving", 10, 1);
	std::cout << keller << std::endl;
	std::cout << std::endl;
	std::cout << autoDrive << std::endl;
	std::cout << std::endl;
	keller.signForm(autoDrive);
	std::cout << std::endl;
	std::cout << autoDrive << std::endl;

	return 0;
}