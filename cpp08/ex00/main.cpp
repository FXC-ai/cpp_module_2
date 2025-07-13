#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

class Display
{
	public :
		template <typename T>
		void operator()(T a)
		{
			std::cout << a << " "; 
		}
};

int main ()
{
	std::vector<int> vector0;

	vector0.push_back(3);
	vector0.push_back(1);
	vector0.push_back(4);
	vector0.push_back(28000000);

	std::cout << "TEST 0 : research 55 in vector<int> : ";
	for_each(vector0.begin(), vector0.end(), Display());
	std::cout << std::endl;
	if (easyfind(vector0, 55) == vector0.end())
	{
		std::cout << "Result : Not found" << std::endl;
	}
	else
	{
		std::cout << "Result : Found" << std::endl;
	}
	std::cout << std::endl;


	std::deque<int> deque0;

	deque0.push_back(3);
	deque0.push_back(1);
	deque0.push_back(4);
	deque0.push_back(28000000);
	std::cout << "TEST 1 : research 28000000 in deque<int> : ";
	for_each(deque0.begin(), deque0.end(), Display());
	std::cout << std::endl;

	if (easyfind(deque0, 28000000) == deque0.end())
	{
		std::cout << "Result : Not found" << std::endl;
	}
	else
	{
		std::cout << "Result : Found" << std::endl;
	}
	std::cout << std::endl;

	std::list<int> list0;
	list0.push_back(3);
	list0.push_back(1);
	list0.push_back(4);
	list0.push_back(1);
	list0.push_back(5);
	list0.push_back(9);
	list0.push_back(42);

	std::cout << "TEST 2 : research 42 in list<int> : ";
	for_each(list0.begin(), list0.end(), Display());
	std::cout << std::endl;

	if (easyfind(list0, 42) == list0.end())
	{
		std::cout << "Result : Not found" << std::endl;
	}
	else
	{
		std::cout << "Result : Found" << std::endl;
	}
	return 0;
}