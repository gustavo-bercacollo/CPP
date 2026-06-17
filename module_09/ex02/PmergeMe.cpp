#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **begin, char **end)
{
    while (begin != end)
    {
        std::string str(*begin);
        if (str.empty())
            throw std::runtime_error("Error");

        size_t start = 0;
        
        if (str[0] == '+')
            start = 1;
        if (start == str.length())
                    throw std::runtime_error("Error");
        for (size_t i = start; i < str.length(); i++)
        {
            if (!isdigit(str[i]))
                throw std::runtime_error("Error is not a digit");
        }
        long value = std::atol(str.c_str());
        if (value > INT_MAX)
            throw std::runtime_error("Error");
        _vec.push_back(value);
        _deq.push_back(value);
        ++begin;
    }
}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

static void printBefore(const std::vector<int>& vec)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";

    std::cout << std::endl;
}

void printAfter(const std::vector<int>& v)
{
    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

void fordJohnson(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        int a = vec[i];
        int b = vec[i + 1];

        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    int leftover = -1;

    if (vec.size() % 2 != 0)
        leftover = vec.back();
    std::vector<int> mainChain;
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }
    std::sort(mainChain.begin(), mainChain.end());

    for (size_t i = 0; i < pend.size(); i++)
    {
        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);

        mainChain.insert(it, pend[i]);
    }
    if (leftover != -1)
    {
        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), leftover);

        mainChain.insert(it, leftover);
    }
    vec = mainChain;
}

void fordJohnsonDeque(std::deque<int>& deq)
{
    if (deq.size() <= 1)
        return;
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        int a = deq[i];
        int b = deq[i + 1];

        if (a > b)
            std::swap(a, b);

        pairs.push_back(std::make_pair(a, b));
    }
    std::deque<int> mainChain;
    std::deque<int> pend;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }
    std::sort(mainChain.begin(), mainChain.end());
    for (size_t i = 0; i < pend.size(); i++)
    {
        std::deque<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);

        mainChain.insert(it, pend[i]);
    }
    if (deq.size() % 2 != 0)
    {
        int leftover = deq.back();

        std::deque<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), leftover);

        mainChain.insert(it, leftover);
    }
    deq = mainChain;
}
void PmergeMe::run()
{
    clock_t start, end;

    printBefore(_vec);

    start = clock();
    fordJohnson(_vec);
    end = clock();

    printAfter(_vec);

    double timeVec = (double)(end - start) / CLOCKS_PER_SEC * 1e6;

    start = clock();
    fordJohnsonDeque(_deq);
    end = clock();

    double timeDeq = (double)(end - start) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : "
              << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque : "
              << timeDeq << " us" << std::endl;
}
