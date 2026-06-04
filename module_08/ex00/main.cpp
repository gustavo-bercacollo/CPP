#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(9);
    vec.push_back(8);
    vec.push_back(4);
    vec.push_back(7);

    try
    {
      std::vector<int>::iterator result = easyfind(vec, 8);
      std::cout << "Find: " << *result << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }

    try
    {
      std::vector<int>::iterator result = easyfind(vec, 99);
      std::cout << "Find: " << *result << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    return 0;
}