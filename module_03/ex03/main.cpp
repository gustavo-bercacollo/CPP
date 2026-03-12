#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap a("Bob");
    DiamondTrap b("Alice");

    a.attack("enemy");
    b.attack("enemy");

    a.whoAmI();
    b.whoAmI();

    DiamondTrap c = a;
    c.whoAmI();

    b = a;
    b.whoAmI();

    return 0;
}
