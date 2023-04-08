#pragma once
#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
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
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& DiamondTrap);
        DiamondTrap& operator=(const DiamondTrap& DiamondTrap);
        ~DiamondTrap();


        void whoAmI();
        int get_hit_points();
	int get_energy_points();
        std::string get_name() const ;
	int get_attack_damage();
        void showInfo();

};

#endif // DiamondTrap_HPP