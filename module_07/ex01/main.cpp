#include "iter.hpp"
#include <iostream>

void print(int &x)
{
  std::cout << x << std::endl;
}

void print(int const &x)
{
    std::cout << x << std::endl;
}
int main(void)
{
  {
    int arr[] = {1, 2 , 3, 4, 5, 6, 7, 8, 9, 10};
    const int size = 10;

    std::cout << "no-cost function" << std::endl;
    iter(arr, size, print);
  }
  {
    const int arr[] = {1, 2 , 3, 4, 5, 6, 7, 8, 9, 10};
    const int size = 10;

    std::cout << "cost function" << std::endl;
    iter(arr, size, print);
  }

  return 0;
}