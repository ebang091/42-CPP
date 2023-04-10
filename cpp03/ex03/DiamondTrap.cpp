#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
:ClapTrap(name + "_clap_name", FragTrap::INIT_HP, ScavTrap::INIT_EP, FragTrap::INIT_AD) ,name(name), ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap constructor called : " <<  name << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout <<"I am both ScavTrap and FragTrap, I am " << name << "and both " << ClapTrap::get_name();
}