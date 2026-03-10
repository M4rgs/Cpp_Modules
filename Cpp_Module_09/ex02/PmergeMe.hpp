#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <algorithm>

class PmergeMe{

    private:
        std::vector<int> vec;
        std::deque<int> deq;
        bool isOdd; 
        int oddLeft;
        PmergeMe();
    public:
        PmergeMe(const PmergeMe &other);
        PmergeMe(int ac , char **av);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();

        bool checkNum(std::string line);
        void insertFollowers(std::vector<int> &mainChain, std::vector<std::pair<int,int> > &sortedPairs);
        void fordSort(std::vector<int> &seq);
        void vecSort();
        // void deqSort();
        void printSorted(std::vector<int>mainchain);
};

#endif