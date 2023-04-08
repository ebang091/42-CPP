#pragma once
#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
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
        FragTrap(std::string name);
        FragTrap(const FragTrap& copy);
        FragTrap& operator=(const FragTrap& copy);
        ~FragTrap();

        void highFiveGuys(void);

		int get_hit_points();
		int get_energy_points();
		std::string get_name() const ;
		int get_attack_damage();
		void showInfo();

		static int get_init_hp();
		static int get_init_ep();
		static int get_init_ad();

};

#endif // FragTrap_HPP