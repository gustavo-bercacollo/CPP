#include <iostream>
#include "Array.hpp"

int main()
{
    // test 1: integer array
    Array<int> numbers(5);
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    std::cout << "numbers[0] = " << numbers[0] << std::endl;
    std::cout << "numbers[1] = " << numbers[1] << std::endl;
    std::cout << "numbers[2] = " << numbers[2] << std::endl;
    std::cout << "size: " << numbers.size() << std::endl;

    try
    {
        numbers[99] = 5;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: index out of bounds!" << std::endl;
    }

    return 0;
}