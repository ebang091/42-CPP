#pragma once
#ifndef Floor_HPP
# define Floor_HPP

class Floor
{
private:
    int idx;
    int max_len;
    AMateria **p;
public:
        Floor();
        Floor(const Floor& Floor);
        Floor& operator=(const Floor& Floor);
        ~Floor();
};

#endif // Floor_HPP