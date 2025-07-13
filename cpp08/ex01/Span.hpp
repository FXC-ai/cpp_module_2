#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>


class Span
{
	public :
		Span();
		Span(unsigned int N);
		Span(const Span & src);
		~Span();

		Span & 						operator=(const Span & rhs);
		unsigned int 				get_N() const;
		const std::vector<int> &	get_datas() const;

		void						addNumber(int n);
		void						addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last);
		size_t						size();
		int							longestSpan();
		int							shortestSpan();
		int							min();
		int							max();

		class SpanInsufficientSize : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Span size insufficient.";
			}
		};


	private :
		std::vector<int>	_datas;
		unsigned int 		_N;

};






#endif