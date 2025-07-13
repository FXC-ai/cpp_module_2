#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T & haystack, const int & needle)
{
	return find(haystack.begin(), haystack.end(), needle);
}

#endif