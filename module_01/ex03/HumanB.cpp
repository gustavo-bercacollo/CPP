#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their "
                  << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon" << std::endl;
}