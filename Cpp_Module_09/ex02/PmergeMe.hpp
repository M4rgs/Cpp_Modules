#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <sstream>

class PmergeMe{

    private:
        std::vector<int> vec;
        std::deque<int> deq;
        bool isOdd; 
        PmergeMe();
    public:
        PmergeMe(const PmergeMe &other);
        PmergeMe(int ac , char **av);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();

        bool checkNum(std::string line);
        void vecSort();
        // void deqSort();
        // void print();
};

#endif