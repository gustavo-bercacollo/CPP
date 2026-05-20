#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

static void typeConvertion(const std::string &str, double &value, bool &isValid)
{
    char *end;

    if (str.size() == 3 && str[0] == '\'' && str[str.size()-1] == '\'')
    {
        isValid = true;
        value = static_cast<double>(str[1]);
    }
    long result = strtol(str.c_str(), &end, 10);
    if (*end == '\0')
    {
        isValid = true;
        value = static_cast<double>(result);
    }

    if (str.find('.') != std::string::npos && str[str.size()-1] == 'f')
    {
        isValid = true;
        std::string noF = str.substr(0, str.size() - 1);
        value = strtod(noF.c_str(), &end);
    }

    if (str.find('.') != std::string::npos && str[str.size()-1] != 'f')
    {
        isValid = true;
        value = strtod(str.c_str(), &end);
    }

    if (str == "nan" || str == "nanf")
    {
        isValid = true;
        value = std::numeric_limits<double>::quiet_NaN();
    }
    else if (str == "+inf" || str == "+inff")
    {
        isValid = true;
        value = std::numeric_limits<double>::infinity();
    }
    else if (str == "-inf" || str == "-inff")
    {
        isValid = true;
        value = -std::numeric_limits<double>::infinity();
    }
}

static void printConversions(double &value, bool &isValid)
{
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127 || !isValid)
        std::cout << "Impossible" << std::endl;
    else if(isprint(value))
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "Not exible" << std::endl;
    
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN || !isValid)
        std::cout << "Impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
    
    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value) && value > 0)
        std::cout << "+inff" << std::endl;
    else if (std::isinf(value) && value < 0)
        std::cout << "-inff" << std::endl;
    else if (!isValid)
       std::cout << "Impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;

    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value) && value > 0)
        std::cout << "+inf" << std::endl;
    else if (std::isinf(value) && value < 0)
        std::cout << "-inf" << std::endl;
    else if (!isValid)
        std::cout << "Impossible" << std::endl;
    else
        std::cout << value << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    bool isValid = false;
    double value = 0;

    if (str.empty()) return;

    typeConvertion(str, value, isValid);
    printConversions(value, isValid);
}
