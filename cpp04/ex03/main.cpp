#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
int main(void)
{
    
    {
        std::cout << std::endl << std::endl;
        std::cout << "AMateria  test\n";
        std::cout << "copy operator test\n";

        AMateria *m1 = new Cure();
        AMateria *m2 = new Ice();
        std::cout << m1->getType() << std::endl;
        std::cout << m2->getType() << std::endl;

        *m2 = *m1;
        std::cout << m1->getType() << std::endl;
        std::cout << m2->getType() << std::endl;

        std::cout << "\nclone test\n";
        AMateria *c1 = m1->clone();
        std:: cout << c1->getType();
        std::cout << std::endl << std::endl;
        delete m1;
        delete m2;
        delete c1;
    }
    {
        std::cout << std::endl << std::endl;
        std::cout << "Materia Inherit test\n";
        Cure *c =  new Cure();
        //~AMateria도  호출되어야.
        delete c;
    }
    {
        std::cout << std::endl << std::endl;
        std::cout << "test ICharacter \n";


        AMateria *am = new Cure();
        ICharacter *ch = new Character("character 1");
        ICharacter *ch2 = new Character("character 2");

        ch->equip(am);
        ch->use(0, *ch2);
        //ICharacter, cure 둘다 삭제되어야.
        delete am;
        delete ch;
        delete ch2;   
    }
    {


    }
    {
        //  IMateriaSource* src = new MateriaSource();
        // src->learnMateria(new Ice());
        // src->learnMateria(new Cure());

        // ICharacter* me = new Character("me");
        // AMateria* tmp;
        // tmp = src->createMateria("ice");
        // me->equip(tmp);
        // tmp = src->createMateria("cure");
        // me->equip(tmp);
        // ICharacter* bob = new Character("bob");
        // me->use(0, *bob);
        // me->use(1, *bob);
        // delete bob;
        // delete me;
        // delete src;
    }
    return 0;
}
