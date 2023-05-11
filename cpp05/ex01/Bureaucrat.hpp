#pragma once
#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include <iostream>
#include "Form.hpp"
class Form;

class Bureaucrat
{
private:
        static const int HIGHEST_GRADE;
        static const int LOWEST_GRADE;
        const std::string name;
        int grade;
public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();

        int getGrade() const;
        std::string getName() const;
        void setGrade(int grade);
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &f);
        
        //이전과 다르게 public으로 선언
        class GradeTooHighException: public std::exception{
                virtual const char *what(void) const throw();
        };
        class GradeTooLowException: public std::exception{
                virtual const char *what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif // Bureaucrat_HPP