#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}
bool PmergeMe::checkNum(std::string line)
{
    if (line.empty())
        return false;
    for (size_t i = 0; i < line.size(); i++)
    {
        if (!isdigit(line[i]))
            return (false);
    }
    if (atoi(line.c_str()) < 0)
        return false;
    return true;
}

PmergeMe::PmergeMe(int ac, char **av)
{
    this->isOdd = false;
    if (ac == 1)
    {
        std::cerr << "Usage : " << av[0] << " <positive numbers sequence>\n";
        exit(1);
    }
    if (ac % 2 != 0)
        this->isOdd = true;
    for (int i = 1; av[i] ; i++)
    {
        int tmp;
        
        if (!checkNum(std::string(av[i])))
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }

        std::stringstream ss(av[i]);
        ss >> tmp;

        if (ss.fail())
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        this->vec.push_back(tmp);
        this->deq.push_back(tmp);
    }

}

void PmergeMe::vecSort()
{
    unsigned int sum = this->vec.size() / 2;

    std::vector<int>first_half; 
    std::vector<int>second_half;

    for (unsigned int i = 0; i < sum; i++)
        first_half.push_back(this->vec[i]);

    for (; sum < this->vec.size(); sum++)
        second_half.push_back(this->vec[sum]);

    std::cout << "first half : " << std::endl;
    for (unsigned int i = 0; i < first_half.size(); i++)
        std::cout << first_half[i] << " ";

    std::cout << std::endl;

    std::cout << "second half : " << std::endl;
    for (unsigned int i = 0; i < second_half.size(); i++)
        std::cout << second_half[i] << " ";
    std::cout << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->vec = other.vec;
        this->deq = other.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{

}