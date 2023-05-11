#pragma once
#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
        static const int SIGN = 145;
        static const int EXEC = 137;
public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
        ~ShrubberyCreationForm();

        virtual void execute(Bureaucrat const & executor) const
        {
                AForm::check(executor);
                
                std::string filename = this->getName() + "_shrubbery";
                std::ofstream file(filename.c_str());
                if (!file.is_open()) {
                        std::cerr << "Error: could not create file " << filename << std::endl;
                        return;
                }
                       file << " _____   _                             ___  _____  _____                      _ \n"
                        "|_   _| | |                           /   |/ __  \\/  ___|                    | |\n"
                        "  | |   | |      ___  __   __  ___   / /| |`' / /'\\ `--.   ___   ___   _   _ | |\n"
                        "  | |   | |     / _ \\ \\ \\ / / / _ \\ / /_| |  / /   `--. \\ / _ \\ / _ \\ | | | || |\n"
                        " _| |_  | |____| (_) | \\ V / |  __/ \\___  |./ /___/\\__/ /|  __/| (_) || |_| || |\n"
                        " \\___/  \\_____/ \\___/   \\_/   \\___|     |_/\\_____/\\____/  \\___| \\___/  \\__,_||_|\n";

                       



                file.close();
        }

};

#endif // ShrubberyCreationForm_HPP