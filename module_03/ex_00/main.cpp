#include "ClapTrap.hpp"

int main(void)
{
  ClapTrap a("Robot");

  a.attack("Enemy");
  a.takeDamage(3);
  a.beRepaired(2);

  a.takeDamage(10);
  a.attack("Enemy");
  a.beRepaired(5);

  return 0;

}
