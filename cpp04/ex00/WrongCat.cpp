#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "Dog";
}

WrongCat::WrongCat(const WrongCat& copy)
{
	this->type = copy.type;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	this->type = copy.type;
	return *this;
}

WrongCat::~WrongCat()
{}