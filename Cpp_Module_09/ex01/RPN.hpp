#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <limits>

class RPN {

    private:
        std::stack<long long> st;
    public:
        RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN& other);
        ~RPN();

        bool checkRPN(std::string line);
        void execRPN(std::string line);
        long long execOp(long long v1, long long v2, char op);
        bool isOp(char op);

        
};
#endif