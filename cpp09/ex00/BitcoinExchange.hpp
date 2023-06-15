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
typedef std::map<std::string, double> Dataform;
class BitcoinExchange
{
private:

        DataForm Data;
        DataForm inputData;
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& copy);
        ~BitcoinExchange();
public:
        static bool cmp(std::pair<int, double>  a, std::pair<int, double> b);
        static bool InvalidDateCheck(int year, int month, int date);
        static void dateValidate(std::string strDate);
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