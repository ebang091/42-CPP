#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, SIGN, EXEC)
{
    std::cout << "RobotomyRequestForm has been created.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm("RobotomyRequestForm", SIGN, EXEC)
{
     std::cout << "RobotomyRequestForm " << copy.getName() << " copy constructor has been created.\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    std::cout << "(cannot change form's name)\n" ;
    this->setRequiredGradeSign(copy.getRequiredGradeSign());
    this->setRequiredGradeExecute(copy.getRequiredGradeExecute());
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called.\n";
}



