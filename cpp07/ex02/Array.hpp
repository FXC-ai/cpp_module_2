#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{

	public :
		Array<T>()
		{
			this->_tab = nullptr;
			this->_size = 0;
		};

		Array<T>(const unsigned int n)
		{
			this->_size = n;
			this->_tab = new T [n];
		};

		Array<T>(Array const & src)
		{	
			unsigned int tmp_size;
			tmp_size = src.size();

			this->_size = tmp_size;
			this->_tab = new T[tmp_size];

			for (unsigned int i = 0 ; i < tmp_size ; i++)
			{
				this->_tab[i] = src[i];
			}
		}

		~Array<T>()
		{
			delete [] this->_tab;
		};

		Array<T> & operator=(Array const & rhs)
		{
			if (this != &rhs)
			{
				if (this->_size != 0)
				{
					delete [] this->_tab;
				}

				this->_size = rhs.size();
				this->_tab = new T [rhs.size()];

				for (unsigned int i = 0; i < rhs.size(); i++)
				{
					this->_tab[i] = rhs[i];
				}
			}
			return *this;
		}

		T & operator[](unsigned int index) const
		{

			if (index >= this->_size)
			{
				throw std::exception();
			}
			return this->_tab[index];
			
		}

		unsigned int size() const
		{
			return this->_size;
		}

		T *get_tab () const
		{
			return this->_tab;
		}

	private :
		T				*_tab;
		unsigned int	_size;

};

#endif