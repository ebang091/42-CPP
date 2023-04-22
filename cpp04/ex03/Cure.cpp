#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : type("cure")
{
}

Cure::Cure(const Cure &copy)
{
}

Cure &Cure::operator=(const Cure &copy)
{
}

Cure::~Cure()
{
}

void Cure::use(ICharacter &target)
{
	std::cout "* shoots an ice bolt at" << target.getName() << " * " << std::endl;
}

AMateria *Cure::Clone() const
{
	Amateria *ret = new Amateria(this->type);
	return ret;
}