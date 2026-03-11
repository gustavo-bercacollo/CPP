#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("Serena");

    a.attack("enemy");
    a.takeDamage(10);
    a.beRepaired(5);
    a.guardGate();

    ScavTrap b(a);
    ScavTrap c;
    c = a;

    return 0;
}