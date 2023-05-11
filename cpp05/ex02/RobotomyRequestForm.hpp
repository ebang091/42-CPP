#pragma once
#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <cstdlib>
class RobotomyRequestForm : public AForm
{
private:
        static const int SIGN = 72;
        static const int EXEC = 45;
public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
        ~RobotomyRequestForm();

        virtual void execute(Bureaucrat const & executor) const
        {
                AForm::check(executor);
                std::cout << "* drilling noises *" << std::endl;
                if (rand() % 2 == 0) 
                {
                        std::cout << this->getName() << " has been robotomized successfully" << std::endl;
                } 
                else 
                {
                        std::cout << "Robotomy of " << this->getName()  << " failed" << std::endl;
                }
        }

};

#endif // RobotomyRequestForm_HPP