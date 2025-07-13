#include "Array.hpp"

class bidon
{
	public :
		bidon(){};
		void display (){std::cout << "useless class" << std::endl;}
};

int main(int, char**)
{

	std::cout << std::endl;
	std::cout << "Test Construction with no parameters" << std::endl;
	Array<char> noParam;

	std::cout << std::endl;
	std::cout << "Construction with an unsigned int n as a parameter" << std::endl;
	Array<int> arrayInt(3);

	std::cout << std::endl;
	std::cout << "Elements can be accessed through the subscript operator: [ ]." << std::endl;
	arrayInt[0] = 3;
	arrayInt[1] = 1;
	arrayInt[2] = 4;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "arrayInt[" << i << "] = " << arrayInt[i] << std::endl;
	}


	std::cout << std::endl;
	std::cout << "A member function size() that returns the number of elements in the array." << std::endl;
	std::cout << "arrayInt.size() = " << arrayInt.size() << std::endl;

	std::cout << "When accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown." <<std::endl;
	
	try
	{
		std::cout << arrayInt[14] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << " : Index is out of bounds" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Proof that it is possible to create an array with a complex type" << std::endl;
	Array<bidon> test(3);
	test[2].display();

	std::cout << std::endl;
	std::cout << "Use of the operator= overload" << std::endl;
	Array<int> *na = new Array<int>(10);
	Array<int> *nb = new Array<int>(10);
	*na = *nb;
	delete na;
	delete nb;

	std::cout << std::endl;
	std::cout << "Creation of an Array using an other one" << std::endl;
	
	Array<int> *src = new Array<int>(100);
	(*src)[0] = 42;
	std::cout << "(*src)[0] = " << (*src)[0] << std::endl;
	Array<int> *copy = new Array<int>(*src);
	std::cout << "(*copy)[0] = " << (*copy)[0] << std::endl;

	delete src;
	delete copy;

	return 0;
}