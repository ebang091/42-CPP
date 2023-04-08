#include "ScavTrap.hpp"
 const int ScavTrap::init_hp = 100;
 const int ScavTrap::init_ep = 50;
 const int ScavTrap::init_ad = 20;
ScavTrap::ScavTrap(std::string name)
:ClapTrap(name), hit_points(init_hp), energy_points(init_ep), attack_damage(init_ad)
{
    std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy.get_name())
{
    std::cout << "ScavTrap copy 'constructor' called\n";
    this->hit_points = copy.hit_points;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
    *this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    std::cout << "ScavTrap copy 'operator' called\n";
    this->hit_points = copy.hit_points;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;

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

int ScavTrap::get_init_hp()
{
	return init_hp;
}

int ScavTrap::get_init_ep()
{
	return init_ep;
}

int ScavTrap::get_init_ad()
{
	return init_ad;
}