#include "Span.hpp"

Span::Span()
{

}

Span::Span(unsigned int n)
{
    this->N = n;
}

Span::Span(const Span &other)
{
    if (this != &other)
        return;
    *this = other;
}

Span &Span::operator=(const Span& other)
{
    if (this != &other)
    {
        if (this->vect.size() > 0)
            this->vect.clear();
        for (unsigned int i = 0; i < other.vect.size(); i++)
            this->vect.push_back(other.vect[i]);
        this->N = other.N;
    }
    return (*this);
}

void Span::addNumber(unsigned int newNumber)
{
    if (this->N == this->vect.size())
        throw CouldNotAdd();
    this->vect.push_back(newNumber);
}

long long Span::shortestSpan()
{
    if (this->vect.size() <= 1)
        throw CouldNotFindSpan();

    std::vector<int> tmp = this->vect;
    std::sort(tmp.begin(), tmp.end());

    long long shortest = static_cast<long long>(tmp[1]) - tmp[0];

    for (size_t i = 1; i < tmp.size() - 1; i++)
    {
        long long temp = static_cast<long long>(tmp[i + 1]) - static_cast<long long>(tmp[i]);
        if (temp < shortest)
            shortest = temp;
    }

    return shortest;
}

void Span::addNumbers(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
    if (this->N == this->vect.size())
        throw CouldNotAdd();
    for (;this->vect.size() < N && beg < end; beg++)
        this->vect.push_back(*beg);
}

long long Span::longestSpan()
{

    if (this->vect.size() <= 1)
        throw CouldNotFindSpan();

    std::vector<int>tmp = this->vect;
    std::sort(tmp.begin(), tmp.end());

    long long biggest = static_cast<long long>(tmp.back()) - static_cast<long long>(tmp[0]);
    return biggest;
}


Span::~Span()
{

}

