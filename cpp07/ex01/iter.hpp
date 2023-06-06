#pragma once
#ifndef iter_HPP
# define iter_HPP

template <typename T>
void iter(T *array, unsigned int len, void (*fp)()){
    for(unsigned int i = 0; i < len; i++){
        fp(array[i]);
    }
}


#endif // iter_HPP