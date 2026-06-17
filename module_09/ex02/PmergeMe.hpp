#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>

class PmergeMe
{
private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

    void sortVector();
    void sortDeque();

public:
    PmergeMe();
    PmergeMe(char **begin, char **end);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void run();
};

#endif