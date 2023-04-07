#include "ClapTrap.hpp"
 int ClapTrap::hit_points = 10;
 int ClapTrap::energy_points = 10;
 int attack_damage = 0;

ClapTrap::ClapTrap(std::string name)
:name(name) {std::cout << "construnctor called : [" << name << "]  created.\n";}

ClapTrap::ClapTrap(const ClapTrap& copy)
:name(copy.name)
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
	return attack_damage;
}

int ClapTrap::get_hit_points()
{
	return hit_points;
}

int ClapTrap::get_energy_points()
{
	return energy_points;
}

std::string ClapTrap::get_name() const
{
	return this->name;
}

void ClapTrap::showInfo()
{
	std::cout << "ClapTrap name : " << name << " " << " hit point : " << hit_points << " " << "energy points : " << energy_points << " " << "attack_damage : " << attack_damage << "\n";
}