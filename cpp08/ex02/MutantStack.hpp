#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
	 	MutantStack<T>();
		MutantStack<T>(const MutantStack<T> & src);
	 	~MutantStack<T>(){};
		MutantStack<T> & operator=(const MutantStack<T> & rhs);
		std::deque<T> get_c() const;

		typedef typename std::deque<T>::iterator iterator;

		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}
};

#endif