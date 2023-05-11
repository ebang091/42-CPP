#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern i1 = Intern();
    Bureaucrat b1 = Bureaucrat("ebang", 1);
    AForm *f;

    std::cout << "\nTest1 : intern should make presidential pardon test.\n";
    try
    {
        f = i1.makeForm("presidential pardon", "target1");
        b1.signForm(*f);
        b1.executeForm(*f);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nTest2 : intern should make Robotomy Request test.\n";
    try {
        f = i1.makeForm("robotomy request", "target2");
        b1.signForm(*f);
        b1.executeForm(*f);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nTest3 : intern should make Shruberry Creation test.\n";
    try {
        f = i1.makeForm("shruberry creation", "target2");
        b1.signForm(*f);
        b1.executeForm(*f);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

     std::cout << "\nTest4 : intern should fail to make form.\n";
    try {
        f = i1.makeForm("shruberry creatio", "target2");
        b1.signForm(*f);
        b1.executeForm(*f);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}