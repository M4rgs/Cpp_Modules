#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe pmergeMe(ac, av);
    clock_t startvec = clock();
    pmergeMe.vecSort();
    clock_t endvec = clock();

    clock_t startdeq = clock();
    pmergeMe.deqSort();
    clock_t enddeq = clock();

    pmergeMe.printSorted();

    double vecFinal = static_cast<double>(endvec - startvec) / CLOCKS_PER_SEC * 1000;
    double deqFinal = static_cast<double>(enddeq - startdeq) / CLOCKS_PER_SEC * 1000;
    
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector :" << std::fixed << std::setprecision(6) << vecFinal << "us" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque :" << std::fixed << std::setprecision(6) << deqFinal << "us" << std::endl;
}