#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span{
    private:
        unsigned int N;
        std::vector<int>vect;
    public: 
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(unsigned int newNum);



        class CouldNotAdd : public std::exception 
        {
            public:
                const char* what() const throw()
                {
                    return "Can't Add The Number !";
                }
        };
};



#endif