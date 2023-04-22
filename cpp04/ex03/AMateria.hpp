#pragma once
#ifndef AMateria_HPP
#define AMateria_HPP

class AMateria
{
protected:
	std::string const &type;

public:
	AMateria(std::string const &type);
	AMateria(const AMateria &copy);
	AMateria &operator=(const AMateria &copy);
	virtual ~AMateria();

	std::string const &getType() const;

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif // AMateria_HPP