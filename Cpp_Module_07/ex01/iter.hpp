#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>

void iter(T* arr, const std::size_t N, void (*fu)(T &))
{
    if (!arr || !fu)
        return;
    for (std::size_t i = 0; i < N; i++)
        fu(arr[i]);
}


template<typename T>

void iter(T* arr, const std::size_t N, void (*fu)(const T &))
{
    if (!arr || !fu)
        return;
    for (std::size_t i = 0; i < N; i++)
        fu(arr[i]);
}


#endif
