#include "Functions.hpp"
#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
  switch (rand() % 3)
  {
    case 0: return new A();
    case 1: return new B();
    default: return new C();
  }
}

void identify(Base* p)
{
  if (dynamic_cast<A*>(p))
      std::cout << "A\n";
  else if (dynamic_cast<B*>(p))
    std::cout << "B\n";
  else if (dynamic_cast<C*>(p))
    std::cout << "C\n";
  else
    std::cout << "Invalid";
}

void identify(Base& p)
{
  try { (void)dynamic_cast<A&>(p); std::cout << "A\n";} catch(...)  {}
  try { (void)dynamic_cast<B&>(p); std::cout << "B\n";} catch(...)  {}
  try { (void)dynamic_cast<C&>(p); std::cout << "C\n";} catch(...)  {}
}
