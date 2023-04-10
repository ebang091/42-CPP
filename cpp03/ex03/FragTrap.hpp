#pragma once
#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
        std::string name;
		int hit_points;
		int energy_points;
		int attack_damage;

protected: 
enum{
	INIT_HP = 100,
	INIT_EP = 100,
	INIT_AD = 30
};
        
public:
        FragTrap(std::string name);
        FragTrap(const FragTrap& copy);
        FragTrap& operator=(const FragTrap& copy);
        ~FragTrap();

        void highFiveGuys(void);


};

#endif // FragTrap_HPP