#pragma once
#ifndef ClapTrap_HPP
# define ClapTrap_HPP

#include <iostream>

class ClapTrap
{
private:
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage;
public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& claptrap);
		ClapTrap& operator=(const ClapTrap& copy);
		~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		int get_hit_points();
		std::string &get_name();
		int get_attack_damage();
		void set_attack_damage(int amount);
};

#endif // ClapTrap_HPP