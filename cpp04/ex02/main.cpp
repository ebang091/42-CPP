#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


void check()
{
	system("leaks AnimalBrain");
}

int main()
{

	{
		Cat cat1;
		cat1.setIdea("hi I'm cat 1.");
		cat1.setIdea("hello.");
		cat1.showIdeas();
	}
	{
		Dog dog1;
		dog1.setIdea("hi I'm dog1.");
		dog1.setIdea("hello.");
		dog1.showIdeas();

	}

	// atexit(check);
}
