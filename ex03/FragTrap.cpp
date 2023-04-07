#include "FragTrap.hpp"
int FragTrap::hit_points = 100;
int FragTrap::energy_points = 100;
int FragTrap::attack_damage = 30;
FragTrap::FragTrap(std::string name)
:ClapTrap(name)
{
    std::cout << "Fraptrap constructor called.\n";
}

FragTrap::FragTrap(const FragTrap& FragTrap) : ClapTrap(FragTrap.get_name())
{
    std::cout << "Fraptrap copy constructor called.\n";
    *this = FragTrap;
}

FragTrap& FragTrap::operator=(const FragTrap& FragTrap)
{
    std::cout << "Fraptrap copy operator called.\n";
    return *this;
}

FragTrap::~FragTrap()
{}

void FragTrap::highFiveGuys()
{
    std::cout << "[ " << get_name() << " ] : " << "let's highfive guys!\n";
}


int FragTrap::get_hit_points()
{
    return hit_points;
}

int FragTrap::get_energy_points()
{
    return energy_points;
}

std::string FragTrap::get_name() const
{
    return this->name;
}

int FragTrap::get_attack_damage()
{
    return attack_damage;
}

void FragTrap::showInfo()
{
    std::cout << "FlagTrap name :" << name << " hit_point : " << hit_points << " attack_damage : " << attack_damage << " energy points : " << energy_points;
}