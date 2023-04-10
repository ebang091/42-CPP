#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
:ClapTrap(name), hit_points(INIT_HP), energy_points(INIT_EP), attack_damage(INIT_AD)
{
    std::cout << "Fraptrap constructor called.\n";
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy.name)
{
    *this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    std::cout << "Fraptrap copy operator called.\n";
    this->hit_points = copy.hit_points;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
    return *this;
}

FragTrap::~FragTrap()
{}

void FragTrap::highFiveGuys()
{
    std::cout << "[ " << get_name() << " ] : " << "let's highfive guys!\n";
}

