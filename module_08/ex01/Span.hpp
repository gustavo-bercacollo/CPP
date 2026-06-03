#pragma once
#include <stdexcept>
#include <algorithm>
#include <vector>

class Span
{
    private:
        unsigned int     _maxSize;
        std::vector<int> _numbers;

    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int n);
        int  shortestSpan();
        int  longestSpan();
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};
