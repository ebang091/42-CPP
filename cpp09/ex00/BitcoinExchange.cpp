#include "BitcoinExchange.hpp"
DataForm BitcoinExchange::Data = DataForm();
DataForm BitcoinExchange::inputData = DataForm();
BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
    this->Data = copy.Data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy){
    if(this != &copy){
        this->Data = copy.Data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange(){
    
}

bool BitcoinExchange::cmp(std::pair<int, double>  a, std::pair<int, double> b){
    if(a.first < b.first)
        return true;
    return false;
}

void BitcoinExchange::dateValidate(std::string strDate){
    int year, month, date;
    
    // std::string check;
    // std::string ret;
    // char *ptr;
    //string YYYY-MM-DD 형태의 날짜를 int형으로 바꾸어 반환한다.
    // .     0123456789

    //TODO : -의 위치를 찾기 : 형식확인하기

    if(strDate[4] != '-' || strDate[7] != '-'){
        throw InvalidDateFailure();
    }
    int integer;
    std::string::iterator it = strDate.begin();
    while(it != strDate.end()){
        integer = 0;
        while(*(it) != '-' && it != strDate.end())
        {
            if(!isdigit(*it))
                throw InvalidDateFailure();
            integer = integer * 10 + *it - '0';
            it++;
        }
        year = integer;
        integer = 0;
        it++;
        while(*(it) != '-' && it != strDate.end())
        {
            if(!isdigit(*it))
                throw InvalidDateFailure();
            integer = integer * 10 + *it - '0';
            it++;
        }
        month = integer;
        integer = 0;
        it++;
        while(it != strDate.end()){
            if(!isdigit(*it))
                throw InvalidDateFailure();
            integer = integer * 10 + *it - '0';
            it++;
        }
        date = integer;
    }




    // check.assign(strDate.c_str(), 0, 4);
    // int year = std::strtod(check.c_str(), &ptr);
    // if()
    //     throw InvalidDateFailure();
    // std::cout << year << "\n";
    // // std::cout << year << " " << month << " " << date <<"\n";
    // check.assign(strDate.c_str(), 5, 2);
    // std::cout << check << "\n";
    // int month = std::strtod(check.c_str(), &ptr);
    // if(ptr != NULL)
    //     throw InvalidDateFailure();
    // std::cout << month << "\n";
    // check.assign(strDate.c_str(), 8, 2);
    // int date = std::strtod(check.c_str(), &ptr);
    // if(ptr != NULL)
    //     throw InvalidDateFailure();
    int intDate = year * 10000 + month * 100 + date;
    if(1900 > year || year > 2023 || month > 12 || month < 1)
        throw InvalidDateFailure();
    try {
        InvalidDateCheck(year, month, date);
        }
    catch(std::exception &e){
        throw e;
    }
        
    return ;
}

void BitcoinExchange::saveDatabaseAndCheckValid(DataForm &data, std::string filename, std::string delimeter){
    std::ifstream database;
    std::string str;

    database.open(filename);
    if(database.rdstate())
    {
        throw DataLoadFailure();
    }
    int isValidDate = VALID;
    int isValidValue = true;
    bool firstLine = true;
    char date[128]; 
    char value[128];
    int whiteSpaceNum;
    // char *ptr;
    while(database.eof() == false){
        std::getline(database, str, '\n');
        if(database.eof())
            break;
        //첫째줄은 넘긴다. 
        if(firstLine) {
            firstLine = false; continue;
        }
        //일단 delimeter를 찾는다.
        //자를 구간을 찾기 위해 공백인 만큼의 개수를 따로 센다.

        //delimeter에서부터 공백의 개수를 센다.
        //그 공백이후의 전체 문자열의 개수를 또 복사해서 값으로 만든다.
        //
        size_t pos = str.find(delimeter, 0);
        if(pos != std::string::npos)//찾았다면
        {
            //date parser
            for(whiteSpaceNum = 0; (0 <= (pos - whiteSpaceNum - 1) && (pos - whiteSpaceNum -1) < str.size()) && str[pos - whiteSpaceNum -1] == ' '; whiteSpaceNum++);
            str.copy(date, pos - whiteSpaceNum, 0);
            date[pos- whiteSpaceNum] = '\0';
            std::string strDate = date;

            //value parser
            for(whiteSpaceNum = 0; (0 <= (pos + whiteSpaceNum + 1) && (pos + whiteSpaceNum + 1) < str.size()) && str[pos + whiteSpaceNum + 1] == ' '; whiteSpaceNum++);
            str.copy(value, str.size() - pos - 1 - whiteSpaceNum , pos + whiteSpaceNum + 1);
            value[str.size() - pos - 1 - whiteSpaceNum] = '\0';
            int intDate;
            //try 받아서 valid 체크하기
            try{
                intDate = strDateToInt(strDate);
            }
            catch(std::exception &e){
                isValidValue = BADINPUT;
            }
            std::string strValue = value;
            std::cout << strValue.c_str() << "\n";
            std::cout << dValue <<"\n";
            // if(ptr != NULL)
            //     isValidValue = BADINPUT;
            data.push_back(std::pair<std::pair<int, double>, std::pair<bool, bool> >(std::make_pair(std::make_pair(intDate, dValue), std::make_pair(isValidDate, isValidValue))));
        }
        else
        {
            database.close();
            throw DataLoadFailure();
        }
    }
    database.close();
    std::cout << "***finish reading database.***\n";
}

void BitcoinExchange::loadData(){
    std::cout << "***start loading data....***\n";
    try
    {
        saveDatabaseAndCheckValid(Data, "data.csv", ",");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        throw e;
    }
}

void BitcoinExchange::checkData(){
    DataForm::iterator it;
    for(it = Data.begin(); it != Data.end(); it++){
        std::cout << it->first.first << " " << it->first.second << " " << it->second.first << "\n";
    }
}

const char *BitcoinExchange::DataLoadFailure::what() const throw ()
{
    return "data load failed.\n";
}

const char *BitcoinExchange::InputDataLoadFailure::what() const throw ()
{
    return "input data load failed.\n";
}


const char *BitcoinExchange::InvalidDateFailure::what() const throw ()
{
    return "not a valid date format.\n";
}

bool BitcoinExchange::InvalidDateCheck(int year, int month, int date){
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            break;
            if (year % 400 == 0){
                if (day > 29)
                    throw InvalidDateFailure();
            }
            else if(year % 100 == 0){
                if(day > 28)
                    throw InvalidDateFailure();
            }
            else if(year % 4 == 0){
                if(day > 29)
                    throw InvalidDateFailure();
            }
            else{
                if(day > 28)
                    throw InputDataLoadFailure();
            }
        case 2:
            if(date < 0 || date > 30 )
                return 1;
            if (year )
            
        case 4:
        case 6:
        case 9:
        case 11:
            if(date < 0 || date > 30)
                return 1;
            break;
        default : 
            return 1;
    }
    return 0;
}

// void BitcoinExchange::parseInputDataAndPrintOutput(std::string filename){
    
//     try{
//         saveDatabaseAndCheckValid(inputData, filename, "|");

//     }
//     catch(std::exception &e){
//         std::cout << e.what() ;
//     }

// }

// int BitcoinExchange::loadExchangeRate(int date){

// }
