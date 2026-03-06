#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN& other)
{
    if (this != &other)
        this->st = other.st;
    return *this;
}

bool RPN::isOp(char op)
{
    return (op == '*' || op == '-' || op == '+' || op == '/');
}

long long RPN::execOp(long long v1, long long v2, char op)
{
    if (op == '-')
        return v1 - v2;
    else if (op == '+')
        return v1 + v2;
    else if (op == '*')
        return v1 * v2;
    else if (op == '/')
        return v1 / v2;
    return 0;
}

bool RPN::checkRPN(std::string line)
{
    std::string tmp;
    std::stringstream ss(line);

    if (line.empty())
        return false;
    while (ss >> tmp)
    {
        if (tmp.size() != 1 || (!isdigit(tmp[0]) && !isOp(tmp[0])))
            return false;
    }
    return true;
}

void RPN::execRPN(std::string line)
{
    std::string tmp;
    std::stringstream ss(line);
    while (!this->st.empty())
        this->st.pop();
    while (ss >> tmp)
    {
        if (isOp(tmp[0]))
        {
            if (this->st.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return ;
            }
            long long v1 = this->st.top();
            this->st.pop();
            long long v2 = this->st.top();
            this->st.pop();
            if (v1 == 0 && tmp[0] == '/')
            {
                std::cerr << "Error : Cannot divide by zero !" << std::endl;
                return ;
            }
            this->st.push(execOp(v2, v1, tmp[0]));
        }
        else 
            this->st.push(tmp[0] - '0');
    }
    if (this->st.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return ;
    }
    std::cout << this->st.top() << std::endl;
}

RPN::~RPN()
{

}