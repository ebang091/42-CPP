#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, SIGN, EXEC)
{
    std::cout << "ShrubberyCreationForm has been created.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy.getName(), SIGN, EXEC)
{
    std::cout << "ShrubberyCreationForm " << copy.getName() << " constructor has been called.\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    std::cout << "(cannot change form's name)\n" ;
    this->setRequiredGradeSign(copy.getRequiredGradeSign());
    this->setRequiredGradeExecute(copy.getRequiredGradeExecute());
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor has been called.\n";
}