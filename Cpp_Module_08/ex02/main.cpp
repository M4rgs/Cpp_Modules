#include "MutantStack.hpp"

int main()
{


    MutantStack<int> myStack;

    myStack.push(15);
    myStack.push(34);

    std::cout << "top of the stack : " << myStack.top() << std::endl;
    std::cout << "size of the stack : " << myStack.size() << std::endl;
    
    myStack.pop();
    std::cout << "size of the stack after pop: " << myStack.size() << std::endl;

    MutantStack<int>secondStack = myStack;

    secondStack.push(12);
    secondStack.push(48);
    secondStack.push(52);
    secondStack.push(122);
    secondStack.push(42);
    secondStack.push(1337);
    MutantStack<int>::iterator be = secondStack.begin();
    MutantStack<int>::iterator en = secondStack.end();

    en--;
    std::cout << "first iterator : " << *be << std::endl;
    std::cout << "last iterator : " << *en << std::endl;

    std::cout << "Stack content:" << std::endl;
    for (; be <= en; be++)
        std::cout << *be << std::endl;
}