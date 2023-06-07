#pragma once
#ifndef iter_HPP
# define iter_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t len, void (*fp)(T&)){
    for(size_t i = 0; i < len; i++){
        fp(array [i]);
    } 
}

template <typename T>
void iter(const T *array, size_t len, void (*fp)(T&)){
    for(size_t i = 0; i < len; i++){
        fp(array [i]);
    } 
}

template <typename T>
void simpleFunction(T & data){
    std::cout << data << " ";
}
#endif // iter_HPP