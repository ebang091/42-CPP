AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria::AMateria(const AMateria &copy) : type(copy.getType())
{
}

AMateria &AMateria::operator=(const AMateria &copy)
{
}

AMateria::~AMateria()
{
}

std::string const &getType() const
{
	return this->type;
}