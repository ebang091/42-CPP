#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	
	{
		FragTrap ft1("seoyoo");
		ScavTrap st1("yejinam");
		ft1.showInfo();
		st1.showInfo();

		st1.attack(ft1.get_ft_name());
		ft1.takeDamage(st1.get_attack_damage());

		ft1.highFiveGuys();

		ft1.showInfo();
		st1.showInfo();


	}
}