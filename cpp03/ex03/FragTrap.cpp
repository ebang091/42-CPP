#include "FragTrap.hpp"
 const int ClapTrap::init_hp = 100;
 const int ClapTrap::init_ep = 100;
 const int ClapTrap::init_ad = 30;
FragTrap::FragTrap(std::string name)
:ClapTrap(name), hit_points(init_hp), energy_points(init_ep), attack_damage(init_ad)
{
    std::cout << "Fraptrap constructor called.\n";
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy.get_name())
{
    std::cout << "Fraptrap copy constructor called.\n";
    this->hit_points = copy.hit_points;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
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

int FragTrap::get_init_hp()
{
	return init_hp;
}

int FragTrap::get_init_ep()
{
	return init_ep;
}

int FragTrap::get_init_ad()
{
	return init_ad;
}