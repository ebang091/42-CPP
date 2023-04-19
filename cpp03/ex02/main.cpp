#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	{
		// ClapTrap ct1("ebang");
		// ClapTrap ct2("seongmik");

		// ct1.showInfo();
		// ct2.showInfo();
		// ct1.beRepaired(5);
		// ct1.attack(ct2.get_name());
		// ct2.takeDamage(ct1.get_attack_damage());

		// ct1.set_attack_damage(10);
		// ct1.attack(ct2.get_name());
		// ct2.takeDamage(ct1.get_attack_damage());
	
		// ct1.showInfo();
		// ct2.showInfo();
		// ScavTrap st1("yejinam");
		// st1.showInfo();
		// st1.attack(ct1.get_name());
		// ct1.takeDamage(st1.get_attack_damage());
		// st1.guardGate();		

		// ct1.showInfo();
		// ct2.showInfo();
		// st1.showInfo();
	}
	{
		FragTrap ft1("seoyoo");
		ScavTrap st1("yejinam");
		ft1.showInfo();
		st1.showInfo();

		st1.attack(ft1.ClapTrap::get_name());
		ft1.takeDamage(st1.get_attack_damage());

		ft1.highFiveGuys();
		
		st1.~ScavTrap();
		ft1.showInfo(); 
		st1.showInfo();
	}
}