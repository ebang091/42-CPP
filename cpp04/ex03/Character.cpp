#include "Character.hpp"
#include "Floor.hpp"
class Floor;

// Floor Character::floor = Floor floor;
Character::Character(const std::string name) : name(name), idx(0)
{
    for(int i = 0 ; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const Character& copy)
{
    //깊은 복사 해야함
    for (int i = 0; i < copy.idx; i++)
        this->inventory[this->idx++] = copy.inventory[i]->clone();
}

Character& Character::operator=(const Character& copy)
{
   //깊은 복사해야함
    if (this != &copy)
    {
        this->name = copy.name;
        for (int i = 0; i < this->idx; i++)
            delete this->inventory[i];
        this->idx = 0;
        for (int i =0; i < copy.idx; i++)
            this->inventory[this->idx++] = copy.inventory[i]->clone();
    }
    return *this;
}

Character::~Character()
{
    for(int i = 0; i < idx; i++)
        delete this->inventory[i];
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *p)
{
    if (this->idx < 4)
        this->inventory[this->idx++] = p;
}

void Character::unequip(int idx)
{
    if(idx < 0 || this->idx <= idx)
        return;

    
}

void Character::use(int idx, ICharacter &target)
{
    if(idx < 0 || this->idx <= idx)
        return;
    this->inventory[idx]->use(target);
}