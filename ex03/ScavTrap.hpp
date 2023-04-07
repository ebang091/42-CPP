#pragma once
#ifndef ScavTrap_HPP
# define ScavTrap_HPP

#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
 private:
        std::string name;
protected: 
        static int hit_points;
	static int energy_points;
	static int attack_damage;
public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& copy);
        ScavTrap& operator=(const ScavTrap& copy);
        ~ScavTrap();

        void guardGate();
        virtual int get_hit_points();
	virtual  int get_energy_points();
	virtual  std::string get_name() const ;
	virtual  int get_attack_damage();
	virtual  void showInfo();

};

#endif // ScavTrap_HPP