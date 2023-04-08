#pragma once
#ifndef ClapTrap_HPP
# define ClapTrap_HPP

#include <iostream>

class ClapTrap
{
private:
		std::string name;
		static const int init_hp;
		static const int init_ep;
		static const int init_ad;

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
		int get_energy_points();
		int get_attack_damage();
		void showInfo();

	 	std::string get_name();
		static int get_init_hp();
		static int get_init_ep();
		static int get_init_ad();
};

#endif // ClapTrap_HPP