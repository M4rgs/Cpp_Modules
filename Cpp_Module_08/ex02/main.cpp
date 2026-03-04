#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::list<int> p;
    p.push_back(4);
    p.push_back(5);
    p.push_back(6);

    MutantStack<int> myStack;
    myStack.push(4);
    myStack.push(5);
    myStack.push(6);

    std::cout << "size of the stack : " << myStack.size() << std::endl;
    std::cout << "size of the list : " << p.size() << std::endl;
    
    std::cout << std::endl;

    std::list<int>::iterator libeg = p.begin();
    MutantStack<int>::iterator beg = myStack.begin();

    std::cout << "list begin : " << *libeg << std::endl;
    std::cout << "mystack begin : " << *beg << std::endl;

    std::cout << std::endl;

    std::list<int>::iterator liend = p.end();
    MutantStack<int>::iterator end = myStack.end();
    --liend;
    --end;
    std::cout << "list end-1 : " << *liend << std::endl;
    std::cout << "mystack end-1 : " << *end << std::endl;

    std::cout << std::endl;

    std::list<int>::reverse_iterator lirbegin = p.rbegin();
    MutantStack<int>::reverse_iterator rbe = myStack.rbegin();

    std::cout << "list rbegin : " << *lirbegin << std::endl;
    std::cout << "mystack rbegin : " << *rbe << std::endl;

    std::cout << std::endl;

    std::list<int>::reverse_iterator rirend = p.rend();
    MutantStack<int>::reverse_iterator rend = myStack.rend();
    --rirend;
    --rend;
    std::cout << "list rend-1 : " << *rirend << std::endl;
    std::cout << "mystack rend-1 : " << *rend << std::endl;

    std::cout << std::endl;

    std::list<int>::const_iterator licbeg = p.begin();
    MutantStack<int>::const_iterator cbe = myStack.begin();
    
    std::cout << "list cbegin : " << *licbeg << std::endl;
    std::cout << "mystack cbegin : " << *cbe << std::endl;

    std::cout << std::endl;

    std::list<int>::const_reverse_iterator licrbegin = p.rbegin();
    MutantStack<int>::const_reverse_iterator crbe = myStack.rbegin();

    std::cout << "list crbegin : " << *licrbegin << std::endl;
    std::cout << "mystack crbegin : " << *crbe << std::endl;

    std::cout << std::endl;

    MutantStack<int> copyStack = myStack;
    MutantStack<int>::iterator copyIt = copyStack.begin();
    std::cout << "copyStack begin : " << *copyIt << std::endl;

}