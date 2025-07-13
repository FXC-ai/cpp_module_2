#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void iter(T *arr_addr, int arr_size, void (&f)(T &))
{
    for (int i = 0; i < arr_size; i++)
    {
        f(arr_addr[i]);
    }
}

template <typename T>
void iter(T *arr_addr, int arr_size, void (&f)(T))
{
    for (int i = 0; i < arr_size; i++)
    {
        f(arr_addr[i]);
    }
}
#endif