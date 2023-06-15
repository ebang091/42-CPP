#pragma once
#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#define FAIL 1
#define SUCCESS 0
#define VALID 0
#define VALUENOTPOSITIVE 1
#define VALUETOOLARGE 2
#define BADINPUT 3

typedef std::vector<std::pair<std::pair<int, double>, std::pair<int, int> > > DataForm;

class BitcoinExchange
{
private:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& copy);
        ~BitcoinExchange();

        static DataForm  Data;
        static DataForm inputData;
        int errorbit;
public:

        static bool cmp(std::pair<int, double>  a, std::pair<int, double> b);
        static bool InvalidDateCheck(int month, int date);
        static int strDateToInt(std::string strDate);
        static void loadData();
        static void checkData();
        static void saveDatabaseAndCheckValid(DataForm &data, std::string filename, std::string delimeter);
        static int loadExchangeRate(int date);
        // void parseInputDataAndPrintOutput(std::string filename);

        class DataLoadFailure: public std::exception{
                virtual const char *what(void) const throw();
        };
        class InputDataLoadFailure: public std::exception{
                virtual const char *what(void) const throw();
        };
        class InvalidDateFailure: public std::exception{
                virtual const char *what(void) const throw();
        };
        class ValueTooLarge: public std::exception{
                virtual const char *what(void) const throw();
        };
        class ValueNotPositive: public std::exception{
                virtual const char *what(void) const throw();
        };



};

#endif // BitcoinExchange_HPP