#pragma once
#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
private:
        static const int SIGN = 25;
        static const int EXEC = 5;
public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
        ~PresidentialPardonForm();
        virtual void execute(Bureaucrat const & executor) const
        {
                AForm::check(executor);
                std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox.\n";
        }
};

#endif // PresidentialPardonForm_HPP