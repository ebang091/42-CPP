#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
:name(name), hit_points(10), energy_points(10), attack_damage(0) {std::cout << "construnctor called : [" << name << "]  created.\n";}

ClapTrap::ClapTrap(const ClapTrap& copy)
:name(copy.name), hit_points(copy.hit_points), energy_points(copy.energy_points), attack_damage(copy.attack_damage)
{
	std::cout << "copy constructor called : " << copy.name << "copied.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	std::cout << "copy operator called.\n";
	this->name = copy.name;
	this->hit_points = copy.hit_points;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
	return *this;
}

ClapTrap::~ClapTrap()
{ std:: cout << "Default destructor called.\n" ;}

void ClapTrap::attack(const std::string &target)
{
	if(this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ": causing [ " << attack_damage <<" ]" << "points of damage!\n";
		this->energy_points--;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " couldn't attack : no energy!\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << "has been damaged" << "[ " << amount << " ]!\n" ;
	if (this->hit_points - amount > 0)
		this->hit_points -= amount;
	else
		this->hit_points = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " got repaired : " << "hit point increased to [ " << this->hit_points + amount << " ]!\n";
		this->energy_points-= amount;
		this->hit_points = this->hit_points + amount;
	}
	else
	{
		std::cout << "ClapTrap" << this->name << "couldn't get  repaired : no energy.\n";
	}
}

int ClapTrap::get_attack_damage()
{
	return this->attack_damage;
}

int ClapTrap::get_hit_points()
{
	return this->hit_points;
}

int ClapTrap::get_energy_points()
{
	return this->energy_points;
}

std::string ClapTrap::get_name() const
{
	return this->name;
}

void ClapTrap::set_attack_damage(int amount)
{
	this->attack_damage = amount;
}

void ClapTrap::set_hit_points(int amount)
{
	this->hit_points = amount;
}

void ClapTrap::set_energy_points(int amount)
{
	this->energy_points = amount;
}

void ClapTrap::set_name(std::string name)
{
	this->name = name;
}

void ClapTrap::showInfo()
{
	std::cout << "name : " << name << " " << " hit point : " << hit_points << " " << "energy points : " << energy_points << " " << "attack_damage : " << attack_damage << "\n";
}