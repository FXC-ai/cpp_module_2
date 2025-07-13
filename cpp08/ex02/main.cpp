#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <list>

class Display
{
	public :
		template <typename T>
		void operator()(T &a) const
		{
			std::cout << a << std::endl;
		}
};

int main()
{
	{
		std::cout << "TEST 0 : Default Constructor" <<std::endl;
		MutantStack<int> mutant0;
		std::cout << std::endl;

		std::cout << "TEST 1 : Inherited member functions" <<std::endl;
		mutant0.push(1);
		mutant0.push(3);
		mutant0.push(21);
		mutant0.push(42);
		std::cout << "mutant0.size() = " << mutant0.size() << std::endl;
		std::cout << "mutant0.top() = " << mutant0.top() << std::endl;
		mutant0.pop();
		std::cout << "mutant0.top() = " << mutant0.top() << std::endl;
		std::cout << std::endl;

		std::cout << "TEST 2 : Iterator of MutantStack" <<std::endl;
		for_each(mutant0.begin(), mutant0.end(), Display());
		std::cout << "TEST 2(bis) : Iterator of MutantStack" <<std::endl;
		MutantStack<int>::iterator it = mutant0.begin();
		std::cout << "*(it + 1) = " << *(it + 1) <<std::endl;
		std::cout << std::endl;

		std::cout << "TEST 3 : Operator = overload" <<std::endl;
		MutantStack<int>mutant1;
		mutant1 = mutant0;
		for_each(mutant1.begin(), mutant1.end(), Display());
		std::cout << std::endl;

		std::cout << "TEST 4 : Copy constructor" <<std::endl;
		MutantStack<int>mutant2(mutant1);
		for_each(mutant2.begin(), mutant2.end(), Display());
		std::cout << std::endl;
	}
	
	std::cout << "----- Subject main -----" <<std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "----- Subject main (std::list) -----" <<std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}

	return 0;
}