#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("default")
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;

    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;

    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energy_points == 0 || hit_points == 0)
    {
        std::cout << "ScavTrap " << name << " can't attack" << std::endl;
        return;
    }

    std::cout << "ScavTrap " << name << " attacks " << target
              << ", causing " << attack_damage << " points of damage!"
              << std::endl;

    energy_points--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name
              << " is now in Gate keeper mode." << std::endl;
}
