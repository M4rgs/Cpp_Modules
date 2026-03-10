#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe pmergeMe(ac, av);
    clock_t start = clock();
    pmergeMe.vecSort();
    clock_t end = clock();
    double vecFinal = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector :" << std::fixed << std::setprecision(6) << vecFinal << "us" << std::endl;
}