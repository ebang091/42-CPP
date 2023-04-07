#pragma once
#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private: 
        std::string name;
protected:
	static int hit_points;
	static int energy_points;
	static int attack_damage;
public:
        FragTrap(std::string name);
        FragTrap(const FragTrap& FragTrap);
        FragTrap& operator=(const FragTrap& FragTrap);
        ~FragTrap();

        void highFiveGuys(void);

        virtual int get_hit_points();
	virtual int get_energy_points();
	virtual std::string get_name() const ;
	virtual int get_attack_damage();
	virtual void showInfo();

};

#endif // FragTrap_HPP