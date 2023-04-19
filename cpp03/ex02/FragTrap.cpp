#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
:ClapTrap(name)
{
    std::cout << "Fraptrap constructor called.\n";
    set_hit_points(100), set_energy_points(100), set_attack_damage(30);
}

FragTrap::FragTrap(const FragTrap& FragTrap) : ClapTrap(FragTrap.ClapTrap::get_name())
{
    std::cout << "Fraptrap copy constructor called.\n";
    *this = FragTrap;
}

FragTrap& FragTrap::operator=(const FragTrap& FragTrap)
{
    std::cout << "Fraptrap copy operator called.\n";
     this->set_attack_damage(get_attack_damage());
    this->set_energy_points(get_energy_points());
    this->set_hit_points(get_hit_points());
    this->set_name(FragTrap.ClapTrap::get_name());
    return *this;
}

FragTrap::~FragTrap()
{}

void FragTrap::highFiveGuys()
{
    std::cout << "[ " << get_name() << " ] : " << "let's highfive guys!\n";
}