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
    for (int i = 1; av[i] ; i++)
    {
        long long tmp;
        
        if (!checkNum(std::string(av[i])))
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }

        std::stringstream ss(av[i]);
        ss >> tmp;

        if (ss.fail() || tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min())
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        this->vec.push_back(tmp);
        this->deq.push_back(tmp);
    }

}

void PmergeMe::printSorted(std::vector<int>mainchain)
{
    std::cout << "Before : ";
    for (unsigned int i = 0; i < this->vec.size(); i++)
    {
        std::cout << this->vec[i];
        if (i != this->vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << "After  : ";
    for (unsigned int i = 0; i < mainchain.size(); i++)
    {
        std::cout << mainchain[i];
        if (i != mainchain.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::insertFollowers(std::vector<int> &mainChain, std::vector<std::pair<int,int> > &sortedPairs)
{
    for (unsigned int i = 1; i < sortedPairs.size(); i++)
    {
        int follower = sortedPairs[i].first;
        int leader   = sortedPairs[i].second;
        
        std::vector<int>::iterator bound = std::upper_bound(mainChain.begin(), mainChain.end(), leader);
        std::vector<int>::iterator pos   = std::upper_bound(mainChain.begin(), bound, follower);
        mainChain.insert(pos, follower);
    }
    if (this->isOdd)
    {
        std::vector<int>::iterator pos = std::upper_bound(mainChain.begin(), mainChain.end(), this->oddLeft);
        mainChain.insert(pos, this->oddLeft);
    }
}

void PmergeMe::fordSort(std::vector<int> &seq)
{
    if (seq.size() <= 1)
        return;

    if (seq.size() % 2 != 0)
    {
        this->isOdd = true;
        this->oddLeft = seq[seq.size() - 1];
    }

    std::vector<std::pair<int,int> > pairs;

    for (unsigned int i = 0; i + 1 < seq.size(); i += 2)
    {
        int a = seq[i];
        int b = seq[i+1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    std::vector<int> leaders;

    for (unsigned int i = 0; i < pairs.size(); i++)
        leaders.push_back(pairs[i].second);

    fordSort(leaders);

    std::vector<std::pair<int,int> > sortedPairs;
    std::vector<bool> used(pairs.size(), false);

    for (unsigned int i = 0; i < leaders.size(); i++)
    {
        for (unsigned int j = 0; j < pairs.size(); j++)
        {
            if (!used[j] && pairs[j].second == leaders[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    std::vector<int> mainChain;
    mainChain.push_back(sortedPairs[0].first);

    for (unsigned int i = 0; i < sortedPairs.size(); i++)
        mainChain.push_back(sortedPairs[i].second);

    insertFollowers(mainChain, sortedPairs);

    seq = mainChain;
}

void PmergeMe::vecSort()
{
    std::vector<int> result = this->vec;
    fordSort(result);
    printSorted(result);
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
