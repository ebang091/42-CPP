#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &copy) : AMateria("cure")
{
	this->type = copy.type;	
}

Cure &Cure::operator=(const Cure &copy)
{
	std::cout << "Cure::operator=(const Cure &copy)" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

Cure::~Cure()
{
	std::cout << "~Cure()"<< std::endl;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " * " << std::endl;
}

AMateria *Cure::clone() const
{
	AMateria *ret = new Cure();
	return ret;
}