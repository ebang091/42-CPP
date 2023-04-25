#include "Character.hpp"
const int Character::MAX_SLOTSIZE = 4;
Character::Character(const std::string name) : name(name)
{
    for(int i = 0 ; i < MAX_SLOTSIZE; i++)
        this->slot[i] = NULL;
}

Character::Character(const Character& copy)
{
    //깊은 복사 해야함
    for (int i = 0; i < MAX_SLOTSIZE; i++)
    {
        if(copy.slot[i] != NULL)
            this->slot[i] = copy.slot[i]->clone();
        else
            this->slot[i] = NULL;
    }
}

Character& Character::operator=(const Character& copy)
{
   //깊은 복사해야함
    if (this != &copy)
    {
        this->name = copy.name;
        for (int i = 0; i < MAX_SLOTSIZE; i++)
        {
            if (this->slot[i] != NULL)
            {
                delete this->slot[i];
                this->slot[i] = NULL;
            }
        }
        for (int i =0; i < MAX_SLOTSIZE; i++)
        {
            if(copy.slot[i] != NULL)
                this->slot[i] = copy.slot[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "~Character()" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if(slot[i] != NULL)
            std::cout << slot[i] << std::endl;
    }
    for(int i = 0; i < MAX_SLOTSIZE; i++)
    {
        
        if (this->slot[i] != NULL)
        {
            delete this->slot[i];
            this->slot[i] = NULL;
        }
    }
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *p)
{
    for(int i = 0 ; i < MAX_SLOTSIZE; i++)
    {
        if(this->slot[i] == NULL)
        {
            this->slot[i] = p;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if(idx < 0 || idx >= MAX_SLOTSIZE)
        return;

    
}

void Character::use(int idx, ICharacter &target)
{
    if(idx < 0 || MAX_SLOTSIZE <= idx)
        return;
    if(slot[idx] == NULL)
        return;
    this->slot[idx]->use(target);
}