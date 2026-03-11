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

        std::vector<int> sortedVec;
        std::deque<int> sortedDeq;
        PmergeMe();
    public:
        PmergeMe(const PmergeMe &other);
        PmergeMe(int ac , char **av);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();

        bool checkNum(std::string line);


        void insertFollowersVec(std::vector<int> &mainChain, std::vector<std::pair<int,int> > &sortedPairs, bool odd, int oddVal);
        void fordSortVec(std::vector<int> &seq);
        void vecSort();

        void insertFollowersDeq(std::deque<int> &mainChain, std::deque<std::pair<int,int> > &sortedPairs, bool odd, int oddVal);
        void fordSortDeq(std::deque<int> &seq);
        void deqSort();

        void printSorted();
};

#endif