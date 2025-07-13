#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &fst, T &snd)
{
	T tmp;

	tmp = fst;
	fst = snd;
	snd = tmp;
};

template <typename T>
T const & min(T const & fst, T const & snd)
{
	return (snd <= fst ? snd : fst);
}

template <typename T>
T const & max(T const & fst, T const & snd)
{
	return (snd >= fst ? snd : fst);
}

#endif