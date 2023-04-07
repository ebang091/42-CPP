#pragma once
#ifndef ScavTrap_HPP
# define ScavTrap_HPP

#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
 private:
        /* data */
public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& copy);
        ScavTrap& operator=(const ScavTrap& copy);
        ~ScavTrap();

        void guardGate();
        std::string get_st_name() const;

};

#endif // ScavTrap_HPP