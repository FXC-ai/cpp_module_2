#include "Bureaucrat.hpp"

int main() 
{
	std::cout << "------------ Tests cpp05/ex00 ---------------" << std::endl;

	std::cout << "TEST 1 : Bureaucrat : GUY, grade 2" << std::endl;
	try
	{
		Bureaucrat guy("Guy", 2);
		std::cout << guy << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "TEST 2 : Bureaucrat : Ignazio, grade 2" << std::endl;
	try
	{
		Bureaucrat ignazio("Ignazio", 2);
		std::cout << ignazio << std::endl;
		ignazio.incrementGrade();
		std::cout << ignazio << std::endl;
		ignazio.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "TEST 3 : Bureaucrat : José, grade 150" << std::endl;
	try
	{
		Bureaucrat jose("Jose", 150);
		std::cout << jose << std::endl;
		jose.decrementGrade();
		std::cout << jose << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	std::cout << std::endl;
	std::cout << "TEST 4 : Bureaucrat : Nobody, grade 151" << std::endl;
	try
	{
		Bureaucrat nobody("Nobody", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << std::endl;
	std::cout << "TEST 5 : Bureaucrat : God, grade 0" << std::endl;
	try
	{
		Bureaucrat god("God", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}