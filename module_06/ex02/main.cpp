#include "Base.hpp"
#include "Functions.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
  srand(time(NULL));

  Base *p = generate();
  identify(p);
  identify(*p);

  return 0;
}
