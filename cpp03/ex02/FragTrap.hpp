#pragma once
#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
        
public:
        FragTrap(std::string name);
        FragTrap(const FragTrap& FragTrap);
        FragTrap& operator=(const FragTrap& FragTrap);
        ~FragTrap();

        void highFiveGuys(void);

};

#endif // FragTrap_HPP