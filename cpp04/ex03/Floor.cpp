#include "AMateria.hpp"
#include "Floor.hpp"

Floor::Floor() : idx(0), len(10)
{
   this->floor = new AMateria[10];
}

Floor::~Floor()
{
    for(int i = 0; i < idx; i++)
        delete floor[i];
    delete floor;
}

void Floor::dropped(AMateria * p)
{
    if(idx == max_len)//저장 슬롯 늘리기.
    {
        max_len += 10;
        AMateria **ptr = new Amateria*[len];
        for(int i = 0; i < idx; i++)
            ptr[i] = this->floor[i];
        delete this->floor;
        this->floor = ptr;
    }
        this->floor[idx++] = p;
}