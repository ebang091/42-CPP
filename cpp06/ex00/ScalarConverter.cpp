#include "ScalarConverter.hpp"
bool ScalarConverter::isnum = true;
bool ScalarConverter::f_print_flag= true;

ScalarConverter::ScalarConverter() 
{}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    isnum = copy.isnum;
    this->f_print_flag = copy.f_print_flag;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
    if(this != &copy){
        this->f_print_flag = copy.f_print_flag;
    }
    return *this;
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(std::string str){
    isnum = true;
    for(unsigned int i = 0; i < str.length(); i++)
    {
        if(!isdigit(str[i]) && str[i] != '.')
            isnum = false;
    }
    if(str == "nan" || str == "inf" || str[str.length() -1] == 'f')
        isnum = true;
    print_char(str);
    print_int(str);
    print_double(str);
    print_float(str);
}

void ScalarConverter::print_char(std::string str){

    std::cout << "char: ";
    if(str.length() == 1){
        char c = str[0];
        if('0' <= c && c <= '9')
            c -= '0';
        if(c > std::numeric_limits<char>::max() || c < std::numeric_limits<char>::min())
            std::cout << "impossible\n";
        else if(isprint(c) == false)
            std::cout << "Non displayable\n";
        else
            std::cout << "\'" << c << "\'\n";

    }
    else {
        double d = strtod(str.c_str(), NULL);
        char c = static_cast<char>(d);
        if(c > std::numeric_limits<char>::max() || c < std::numeric_limits<char>::min())
            std::cout << "impossible\n";
        else if(isprint(c) == false)
            std::cout << "Non displayable\n";
        else
            std::cout << "\'" << c << "\'\n";
    }
}

void ScalarConverter::print_int(std::string str){
    
    std::cout << "int: ";
    if (isnum == false && str != "nan" && str != "inf" && str != "inff")
    {
        if (str.length() == 1)
            std::cout << static_cast<int>(str[0])  << "\n";
        else
            std::cout << "impossible\n";
    }
    else {
        char *endPtr;
        double d = strtod(str.c_str(), &endPtr);
        int i = static_cast<int>(d);
        if(str == "nan" || str == "inf" || str == "inff")
            std::cout << "impossible\n";
        else if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
            std::cout << "impossible\n";
        else
            std::cout << i << "\n";
    }
}

void ScalarConverter::print_double(std::string str){
    
    std::cout <<"double: ";
    int f_print_flag = 1;
    char *endPtr;

    if(isnum == false){
        if(str.length() == 1)
        {
            double d = static_cast<double>(str[0]);
            std::cout << d << ".0\n";
        }
        else
            std::cout << "impossible\n";
    }
    else{
        long double d = strtod(str.c_str(), &endPtr);
        if(str == "nan" || str =="inf")
            f_print_flag = 0;
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "impossible";
        else {
            std::setprecision(16);
            std::cout << d;
        }
        if(f_print_flag)
                std::cout << ".0";
        std::cout << "\n";
    }
}

void ScalarConverter::print_float(std::string str){
    
    std::cout << "float: ";
    char *endPtr;
     if(isnum == false){
        if(str.length() == 1)
        {
            double d = static_cast<double>(str[0]);
            std::cout << d << ".0\n";
        }
        else
        {
            std::cout << "impossible\n";
        }
    }
    else{
        long double d = strtod(str.c_str(), &endPtr);
        float f = static_cast<float>(d);
        if(str == "nan" || str == "inf")
            f_print_flag = 0;
        if ((f > std::numeric_limits<float>::max() || f < std::numeric_limits<float>::min()) && f != 0)
            std::cout << "impossible\n";
        else {
            std::setprecision(16);
            std::cout << f;
        }
        if(f_print_flag)
            { 
                if(str == "nan")
                    std::cout <<"f\n";
                else
                    std::cout <<".0f\n";           
            }
        else
            std::cout << "\n";
    }
}