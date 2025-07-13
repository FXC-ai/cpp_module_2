#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack & src)
{
	this->c = src.get_c();
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack & rhs)
{
	if (rhs != *this)
	{
		this->c = rhs.get_c();
	}
	return *this;
}

template <typename T>
std::deque<T> MutantStack<T>::get_c() const
{
	return this->c;
}