#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
:ClapTrap(name)
{
    std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& ScavTrap) : ClapTrap(ScavTrap.get_name())
{
    std::cout << "ScavTrap copy 'constructor' called\n";
    *this = ScavTrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    std::cout << "ScavTrap copy 'operator' called\n";
    return *this;
}

ScavTrap::~ScavTrap()
{}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << get_name() << " is now on Gate keeper mode.\n";
}

int ScavTrap::get_hit_points()
{
    return hit_points;
}

int ScavTrap::get_energy_points()
{
    return energy_points;
}

std::string ScavTrap::get_name() const
{
    return this->name;
}

int ScavTrap::get_attack_damage()
{
    return attack_damage;
}

void ScavTrap::showInfo()
{
       std::cout << "ScavTrap name :" << name << " hit_point : " << hit_points << " attack_damage : " << attack_damage << " energy points : " << energy_points;
}
