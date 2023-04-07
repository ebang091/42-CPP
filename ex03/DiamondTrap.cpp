#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(std::string name)
:
{

}
int DiamondTrap::get_hit_points()
{
    return hit_points;
}

int DiamondTrap::get_energy_points()
{
    return energy_points;
}

std::string DiamondTrap::get_name() const
{
    return this->name;
}

int DiamondTrap::get_attack_damage()
{
    return attack_damage;
}

void DiamondTrap::showInfo()
{
       std::cout << "ScavTrap name :" << name << " hit_point : " << hit_points << " attack_damage : " << attack_damage << " energy points : " << energy_points;
}
