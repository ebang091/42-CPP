#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : type("ice")
{
}

Ice::Ice(const Ice &copy)
{
}

Ice &Ice::operator=(const Ice &copy)
{
}

Ice::~Ice()
{
}

void Ice::use(ICharacter &target)
{
	std::cout << "*"
			  << " heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria *Ice::Clone() const
{
	Amateria *ret = new Amateria(this->type);
	return ret;
}