#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
    : ClapTrap("default_clap_name"), FragTrap(), ScavTrap()
{
    name = "default";

    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;

    std::cout << "DiamondTrap " << name << " default constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    this->name = name;

    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;

    std::cout << "DiamondTrap " << name << " constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
    : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        name = other.name;
    }
    //std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
    std::cout << "DiamondTrap name: " << this->name << std::endl;
}

