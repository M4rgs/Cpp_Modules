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
        for (unsigned int i = 0; i < N; i++)
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

Span::~Span()
{

}

