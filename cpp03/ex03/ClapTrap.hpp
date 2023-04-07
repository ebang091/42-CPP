#pragma once
#ifndef ClapTrap_HPP
# define ClapTrap_HPP

#include <iostream>

class ClapTrap
{
private:
		std::string name;
		static int hit_points;
		static int energy_points;
		static int attack_damage;
public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& claptrap);
		ClapTrap& operator=(const ClapTrap& copy);
		~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		int get_hit_points();
		int get_energy_points();
		std::string get_name() const ;
		int get_attack_damage();
		void showInfo();
};

#endif // ClapTrap_HPP