#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array {

    private :
        T *arr;
        unsigned int arrSize;

    public :
        Array()
        {
            this->arrSize = 0;
            this->arr = NULL;
        }

        Array(unsigned int n)
        {
            this->arrSize = n;
            this->arr = new T[this->arrSize];
        }

        Array(const Array &other)
        {
            arrSize = other.arrSize;
            arr = NULL;
            *this = other;
        }

        Array &operator=(const Array &other)
        {
            if (this == &other)
                return *this;

            delete[] arr;
            arr = NULL;

            arrSize = other.arrSize;

            if (arrSize > 0)
            {
                arr = new T[arrSize];
                for (unsigned int i = 0; i < arrSize; i++)
                    arr[i] = other.arr[i];
            }

            return *this;
        }
        class OutOfBound : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Index out of bound !");
                }
        };

        T& operator[](unsigned int index)
        {
            if (index >= this->arrSize)
                throw(OutOfBound());
            return (this->arr[index]);
        }
        unsigned int size() const
        {
            return (this->arrSize);
        }

        ~Array()
        {
            delete [] arr;
        }
};
#endif
