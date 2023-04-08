#pragma once
#ifndef ScavTrap_HPP
# define ScavTrap_HPP

#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
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
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& copy);
        ScavTrap& operator=(const ScavTrap& copy);
        ~ScavTrap();

        void guardGate();

        int get_hit_points();
	int get_energy_points();
	std::string get_name() const ;
	int get_attack_damage();
	void showInfo();

	static int get_init_hp();
	static int get_init_ep();
	static int get_init_ad();

};

#endif // ScavTrap_HPP