#include "iter.hpp"

template <typename T>
void iter(T arr[], int const size, void (*func)(T &))
{
  for (int i = 0; i < size; i++)
    func(arr[i]);
}

template <typename T>
void iter(const T arr[], int const size, void (*func)(const T &))
{
  for (int i = 0; i < size; i++)
    func(arr[i]);
}
