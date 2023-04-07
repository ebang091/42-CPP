#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
:ClapTrap(name)
{
    std::cout << "ScavTrap constructor called\n";
    set_hit_points(100), set_energy_points(50), set_attack_damage(20);
}

ScavTrap::ScavTrap(const ScavTrap& ScavTrap) : ClapTrap(ScavTrap.get_st_name())
{
    std::cout << "ScavTrap copy 'constructor' called\n";
    this->set_attack_damage(get_attack_damage());
    this->set_energy_points(get_energy_points());
    this->set_hit_points(get_hit_points());
    
    *this = ScavTrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    std::cout << "ScavTrap copy 'operator' called\n";
    this->set_hit_points(get_hit_points());
    this->set_attack_damage(get_attack_damage());
    this->set_energy_points(get_energy_points());
    this->set_name(copy.get_st_name());
    return *this;
}

ScavTrap::~ScavTrap()
{}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << get_name() << " is now on Gate keeper mode.\n";
}

std::string ScavTrap::get_st_name() const
{
    return get_name();
}