#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <climits>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

public:
    static void convert(const std::string &str);
};
