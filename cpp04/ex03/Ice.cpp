#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &copy)
{
	this->type = copy.type;	
}

Ice &Ice::operator=(const Ice &copy)
{
	std::cout << "Ice::operator=(const Ice &copy)" << std::endl;
	if(this != &copy)
	{
		this->type = copy.type;	
	}
	return *this;
}

Ice::~Ice()
{
	std::cout << "~Ice()"<< std::endl;
}

void Ice::use(ICharacter &target)
{
	std::cout << "*"
			  << " shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const
{
	AMateria *ret = new Ice();
	return ret;
}