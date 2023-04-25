#pragma once
#ifndef MateriaSource_HPP
# define MateriaSource_HPP

#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
private:
        AMateria *slot[4];
        static const int MAX_SLOTSIZE;
public:
        MateriaSource();
        MateriaSource(const MateriaSource& copy);
        MateriaSource& operator=(const MateriaSource& copy);
        ~MateriaSource();

        virtual void learnMateria(AMateria *);
        virtual AMateria *createMateria(std::string const &type);
};

#endif // MateriaSource_HPP