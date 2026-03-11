#include "FragTrap.hpp"

int main()
{
    FragTrap a("Bob");

    a.attack("enemy");
    a.highFivesGuys();

    FragTrap b(a);
    b.attack("target");

    return 0;
}
