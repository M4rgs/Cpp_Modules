#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>


class NotFound : public std::exception
{
    public:
        const char* what() const throw()
        {
            return ("Element Not Found !");

        }
};

template <typename T>

int easyfind(T &container, int y)
{
    typename T::iterator it = std::find(container.begin(), container.end(), y);
    if (it != container.end())
        return *it;
    throw NotFound();
}


#endif