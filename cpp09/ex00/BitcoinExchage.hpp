#pragma once
#ifndef BitcoinExchage_HPP
# define BitcoinExchage_HPP


#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#define FAIL 1
#define SUCCESS 0

class BitcoinExchage
{
private:
        /* data */
public:
        BitcoinExchage();
        BitcoinExchage(const BitcoinExchage& copy);
        BitcoinExchage& operator=(const BitcoinExchage& copy);
        ~BitcoinExchage();

};

#endif // BitcoinExchage_HPP