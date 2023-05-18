#pragma once
#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP
# define NONDISPLAYABLE 0
# define IMPOSSIBLE 1
#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>
#include <string>

class ScalarConverter
{
private:
        bool isnum;
        bool f_print_flag;
public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& copy);
        ~ScalarConverter();

        void convert(std::string str);

        void print_char(std::string str);
        void print_int(std::string str);
        void print_float(std::string str);
        void print_double(std::string str);
};

#endif // ScalarConverter_HPP