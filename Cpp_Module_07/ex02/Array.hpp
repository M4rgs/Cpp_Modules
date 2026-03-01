#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array {

    private :
        T *arr;
        unsigned int arrSize;

    public :
        Array();

        Array(unsigned int n);

        Array(const Array &other);

        Array &operator=(const Array &other);

        class OutOfBound : public std::exception
        {
            public:
                const char *what() const throw();
        };

        T& operator[](unsigned int index);

        unsigned int size() const;

        ~Array();
};

#include "Array.tpp"

#endif
