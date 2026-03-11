#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("Default"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
    : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
  if (this != &other)
  {
    name = other.name;
    hit_points = other.hit_points;
    energy_points = other.energy_points;
    attack_damage = other.attack_damage;
  }
  return *this;
}

void ClapTrap::attack(const std::string& target)
{
  if (energy_points == 0 || hit_points == 0)
  {
    std::cout << "ClapTrap " << name << " can't attack" << std::endl;
    return;
  }
  std::cout << "ClapTrap " << name << " attacks " << target
          << ", causing " << attack_damage << " points of damage!"
          << std::endl;

  energy_points--;

}

void ClapTrap::takeDamage(unsigned int amount)
{
  if (hit_points <= 0)
  {
    std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
    return;
  }

  std::cout << "ClapTrap " << name << " takes "
          << amount << " points of damage!" << std::endl;

  if (amount >= hit_points)
    hit_points = 0;
  else
    hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
  if (energy_points <= 0 || hit_points <= 0)
    {
        std::cout << "ClapTrap " << name << " can't repair itself!" << std::endl;
        return;
    }
  std::cout << "ClapTrap " << name << " repairs itself for "
          << amount << " hit points!" << std::endl;
  
  hit_points += amount;
  energy_points--;
}

