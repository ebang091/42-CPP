#pragma once
#ifndef WrongCat_HPP
# define WrongCat_HPP

#include "Dog.hpp"

class WrongCat : public Dog
{

public:
		WrongCat();
		WrongCat(const WrongCat& copy);
		WrongCat& operator=(const WrongCat& copy);
		~WrongCat();

		

};

#endif // WrongCat_HPP