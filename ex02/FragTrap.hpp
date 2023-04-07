#pragma once
#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
        /* data */
public:
        FragTrap(std::string name);
        FragTrap(const FragTrap& FragTrap);
        FragTrap& operator=(const FragTrap& FragTrap);
        ~FragTrap();

        void highFiveGuys(void);
        std::string get_ft_name() const;

};

#endif // FragTrap_HPP