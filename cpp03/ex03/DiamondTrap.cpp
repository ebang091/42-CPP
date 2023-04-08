#include "DiamondTrap.hpp"
const int DiamondTrap::init_hp = ScavTrap::get_init_hp();
const int DiamondTrap::init_ep = ScavTrap::get_init_ep();
const int DiamondTrap::init_ad = FragTrap::get_init_ad();


DiamondTrap::DiamondTrap(std::string name)
:ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name), hit_points(init_hp), energy_points(init_ep), attack_damage(init_ad)
{
    std::cout << "DiamondTrap constructor called : " <<  name << std::endl;
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

void DiamondTrap::whoAmI()
{
    std::cout <<"I am both ScavTrap and FragTrap, I am " << name << "and both " << ClapTrap::get_name();
}