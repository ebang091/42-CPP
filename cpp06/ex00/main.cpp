#include "ScalarConverter.hpp"

int main(int argc, char *argv[]){

    if(argc == 1){
        std::cout << "arguments usage : ./convert argument" << std::endl;
        return 1;
    }
    ScalarConverter s;
    s.convert(static_cast<std::string>(argv[1]));
}