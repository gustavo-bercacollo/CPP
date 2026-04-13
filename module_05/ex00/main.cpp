#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
  try
  {
      Bureaucrat b("Gustavo", 1);
      b.incrementGrade();
  }
  catch (std::exception &e)
  {
      std::cout << e.what() << std::endl;
  }

  try
  {
      Bureaucrat b("Gustavo", 150);
      b.decrementGrade();
  }
  catch (std::exception &e)
  {
      std::cout << e.what() << std::endl;
  }

  Bureaucrat a("Gustavo", 42);
  std::cout << a << std::endl;
}
