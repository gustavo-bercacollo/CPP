#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
  if (_numbers.size() == _maxSize)
    throw std::runtime_error("Span is full");
  _numbers.push_back(n);
}

int Span::longestSpan()
{
  if (_numbers.size() == 0 || _numbers.size() == 1)
    throw std::runtime_error("Not enough numbers");
  return (*std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end()));
}

int Span::shortestSpan()
{
  if (_numbers.size() == 0 || _numbers.size() == 1)
    throw std::runtime_error("Not enough numbers");

  std::vector<int> sorted = _numbers;
  std::sort(sorted.begin(), sorted.end());

  int min = sorted[1] - sorted[0];
  for (unsigned int i = 0; i < sorted.size() - 1; i++)
  {
    if ((sorted[i + 1] - sorted[i]) < min)
      min = sorted[i + 1] - sorted[i];
  }
  return min;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator it = begin; it != end; it++)
        addNumber(*it);
}