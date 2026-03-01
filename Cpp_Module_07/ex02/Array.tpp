#include <iostream>


template<typename T>
Array<T>::Array()
{
    this->arrSize = 0;
    this->arr = NULL;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
    this->arrSize = n;
    this->arr = new T[this->arrSize]();
}

template<typename T>
Array<T>::Array(const Array &other)
{
    arrSize = other.arrSize;
    arr = NULL;
    *this = other;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
    if (this == &other)
        return *this;
    delete[] arr;
    arr = NULL;
    arrSize = other.arrSize;
    if (arrSize > 0)
    {
        arr = new T[arrSize]();
        for (unsigned int i = 0; i < arrSize; i++)
            arr[i] = other.arr[i];
    } 
    return *this;
}


template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= this->arrSize)
        throw(OutOfBound());
    return (this->arr[index]);
}

template<typename T>
unsigned int Array<T>::size() const
{
    return (this->arrSize);
}

template<typename T>
Array<T>::~Array()
{
    delete [] arr;
}

template<typename T>
const char *Array<T>::OutOfBound::what() const throw()
{
    return ("Index out of bounds !");
}
