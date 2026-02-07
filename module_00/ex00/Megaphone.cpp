#include "Includes.hpp"

void megafone(std::string str)
{
  for (size_t i = 0; i < str.length(); i++)
    std::cout << (char)toupper(str[i]);
}

int main(int argc, char **argv)
{
  if (argc > 1)
  {
    for (int i = 1; i < argc; i++)
      megafone(argv[i]);
    std::cout << std::endl;
  }
  else
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
};
