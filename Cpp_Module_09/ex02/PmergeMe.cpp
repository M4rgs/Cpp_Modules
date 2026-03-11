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

    long long n;
    std::stringstream ss(line);
    ss >> n;

    if (ss.fail() || n < 0)
        return false;
    return true;
}

PmergeMe::PmergeMe(int ac, char **av)
{
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



void PmergeMe::printSorted()
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

    for (unsigned int i = 0; i < this->sortedVec.size(); i++)
    {
        std::cout << this->sortedVec[i];
        if (i != this->sortedVec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}


void PmergeMe::insertFollowersDeq(std::deque<int> &mainChain, std::deque<std::pair<int,int> > &sortedPairs, bool odd, int oddVal)
{
    std::deque<unsigned int> jacob;

    jacob.push_back(1);
    jacob.push_back(3);

    while (jacob.back() < sortedPairs.size())
        jacob.push_back(jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2]);

    std::deque<unsigned int> order;
    std::deque<bool> used(sortedPairs.size(), false);
    used[0] = true;

    for (size_t k = 0; k < jacob.size(); k++)
    {
        unsigned int idx  = jacob[k];
        unsigned int prev = (k ? jacob[k-1] : 0);

        if (idx < sortedPairs.size() && !used[idx])
        {
            order.push_back(idx);
            used[idx] = true;
        }

        for (int i = idx-1; i > (int)prev; i--)
        {
            if (i < (int)sortedPairs.size() && !used[i])
            {
                order.push_back(i);
                used[i] = true;
            }
        }
    }

    for (size_t i = 1; i < sortedPairs.size(); i++)
        if (!used[i])
            order.push_back(i);

    for (size_t k = 0; k < order.size(); k++)
    {
        unsigned int i = order[k];

        int follower = sortedPairs[i].first;
        int leader   = sortedPairs[i].second;

        std::deque<int>::iterator bound =
            std::upper_bound(mainChain.begin(), mainChain.end(), leader);

        std::deque<int>::iterator pos =
            std::upper_bound(mainChain.begin(), bound, follower);

        mainChain.insert(pos, follower);
    }

    if (odd)
    {
        std::deque<int>::iterator pos =
            std::upper_bound(mainChain.begin(), mainChain.end(), oddVal);

        mainChain.insert(pos, oddVal);
    }
}


void PmergeMe::fordSortDeq(std::deque<int> &seq)
{
    if (seq.size() <= 1)
        return;

    bool odd = seq.size() % 2;
    int oddVal = odd ? seq.back() : 0;

    std::deque<std::pair<int,int> > pairs;

    for (size_t i = 0; i + 1 < seq.size(); i += 2)
    {
        int a = seq[i];
        int b = seq[i+1];

        if (a > b)
            std::swap(a,b);

        pairs.push_back(std::make_pair(a,b));
    }

    std::deque<int> leaders;

    for (size_t i = 0; i < pairs.size(); i++)
        leaders.push_back(pairs[i].second);

    fordSortDeq(leaders);

    std::deque<std::pair<int,int> > sortedPairs;
    std::deque<bool> used(pairs.size(), false);

    for (size_t i = 0; i < leaders.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (!used[j] && pairs[j].second == leaders[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    std::deque<int> mainChain;

    mainChain.push_back(sortedPairs[0].first);

    for (size_t i = 0; i < sortedPairs.size(); i++)
        mainChain.push_back(sortedPairs[i].second);

    insertFollowersDeq(mainChain, sortedPairs, odd, oddVal);

    seq = mainChain;
}



void PmergeMe::insertFollowersVec(std::vector<int> &mainChain, std::vector<std::pair<int,int> > &sortedPairs, bool odd, int oddVal)
{
    std::vector<unsigned int> jacob;

    jacob.push_back(1);
    jacob.push_back(3);

    while (jacob.back() < sortedPairs.size())
    {
        size_t n = jacob.size();
        jacob.push_back(jacob[n-1] + 2 * jacob[n-2]);
    }

    std::vector<unsigned int> order;
    std::vector<bool> used(sortedPairs.size(), false);
    used[0] = true;

    for (size_t k = 0; k < jacob.size(); k++)
    {
        unsigned int idx = jacob[k];
        unsigned int prev = (k ? jacob[k-1] : 0);

        if (idx < sortedPairs.size() && !used[idx])
            order.push_back(idx), used[idx] = true;

        for (int i = idx-1; i > (int)prev; i--)
            if (i < (int)sortedPairs.size() && !used[i])
                order.push_back(i), used[i] = true;
    }

    for (size_t i = 1; i < sortedPairs.size(); i++)
        if (!used[i])
            order.push_back(i);

    for (size_t k = 0; k < order.size(); k++)
    {
        unsigned int i = order[k];
        int follower = sortedPairs[i].first;
        int leader   = sortedPairs[i].second;

        std::vector<int>::iterator bound = std::upper_bound(mainChain.begin(), mainChain.end(), leader);

        std::vector<int>::iterator pos = std::upper_bound(mainChain.begin(), bound, follower);

        mainChain.insert(pos, follower);
    }

    if (odd)
        mainChain.insert(std::upper_bound(mainChain.begin(), mainChain.end(), oddVal),oddVal);
}

void PmergeMe::fordSortVec(std::vector<int> &seq)
{
    if (seq.size() <= 1)
        return;

    bool odd = seq.size() % 2;
    int oddVal = odd ? seq.back() : 0;

    std::vector<std::pair<int,int> > pairs;

    for (size_t i = 0; i + 1 < seq.size(); i += 2)
    {
        int a = seq[i]; 
        int b = seq[i+1];
        if (a > b) 
            std::swap(a, b);
        pairs.push_back(std::make_pair(a,b));
    }

    std::vector<int> leaders;
    for (size_t i = 0; i < pairs.size(); i++)
        leaders.push_back(pairs[i].second);

    fordSortVec(leaders);

    std::vector<std::pair<int,int> > sortedPairs;
    std::vector<bool> used(pairs.size(), false);

    for (size_t i = 0; i < leaders.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
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

    for (size_t i = 0; i < sortedPairs.size(); i++)
        mainChain.push_back(sortedPairs[i].second);

    insertFollowersVec(mainChain, sortedPairs, odd, oddVal);

    seq = mainChain;
}

void PmergeMe::vecSort()
{
    std::vector<int> result = this->vec;
    fordSortVec(result);
    this->sortedVec = result;
}

void PmergeMe::deqSort()
{
    std::deque<int> result = this->deq;
    fordSortDeq(result);
    this->sortedDeq = result;
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
