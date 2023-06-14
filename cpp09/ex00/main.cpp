#include "BitcoinExchage.hpp"

/*
내부에 있는 database 에서 값 불러오기
: 원하는 연-원-일을 갖고 있을 때. 

2011-01-03,0
2011-01-04,9.99
2011-01-05,0.11
2022-03-29,47115.93


1. ','을 기준으로 자르기
2. 날짜부를 '-'를 기준으로 year, month, date 로 자르기
3. 값을 double 형으로 받아오기.

4. 불러온 날짜가 원하는 날짜 이전이면 일단 저장하고 다음으로 이동.
5. 불러온 날짜가 원하는 날짜보다 이미 지난 날짜면 반복문을 탈출하고 값으로 사용.
--------------------------------------

input  받은 database 파싱하기

1. 파일 열 때 에러처리
2. |을 기준으로 날짜부, 값으로 나눈다. 
    2개 초과의 덩어리로 나뉘면 문제.
3. 날짜는 -을 단위로 쪼개서 연,월,일을 나눈다.
4. 날짜는 연은 0이상 2023 이하, 월은 1이상 12이하, 일은 월에 맞는 날짜 기준으로 센다.
    ( 날짜 사이에 -이외의 다른 문자가 있을 경우 오류이다.)

5. 값은 atoi를 쓰거나, 직접 구현하거나, cstr으로 바꾼후 static_cast를 사용하는 방법이 있다.
    생각해보자. 



*/

bool save_database(std::map<std::string, double> &data){
    std::ifstream database;
    std::string str;
    database.open("data.csv");
    if(database.rdstate())
    {
        std::cout << "database read failed.\n";
        return 1;
    }

    bool firstLine = true;
    char date[128]; 
    char exchange_rate[128];
    std::cout << str <<"\n";
    
    while(database.eof() == false){
        std::getline(database, str, '\n');
        if(database.eof())
            break;
        if(firstLine) {
            firstLine = false; continue;
        }
        size_t pos = str.find(",", 0);
        
        if(pos != std::string::npos)//찾았다면
        {
            str.copy(date, pos, 0);
            str.copy(exchange_rate, str.size() - 1 , pos+1);
            std::string str_date = date;
            std::string str_exchage_rate = exchange_rate;
            
            double d_exchange_rate = strtod(str_exchage_rate.c_str(), NULL);
            data.insert(std::pair<std::string, double>(str_date, d_exchange_rate));
        }
        else
        {
            std::cout << "wrong database\n";
            database.close();
            return FAIL;
        }
    }
    database.close();
    std::cout << "finish reading database.\n";
    return SUCCESS;
}

bool cmp(std::pair<std::string, double> a, std::pair<std::string, double> b){
    if(a.first < b.first)
        return true;
    return false;
}

int main(int argc, char **argv){
    if(argc != 2){
        std::cout << "usage : ./btc [input filename]\n";
        return 1;
    }
    std::map<std::string, double> data;
    if(save_database(data)){
        std::cout << "reading database failed.\n";
        return 1;
    }
    sort(data.begin(), data.end(), cmp);
    std::map<std::string, double>::iterator it;
    for(it = data.begin(); it != data.end(); it++){
        std::cout << it->first << " " << it->second << "\n";
    }
    std::ifstream ifs;
    std::string filename = argv[1];
    ifs.open(filename);
    if(ifs.rdstate()){
        std::cout << "error: wrong file\n";
        ifs.close();
        return 1;
    }
}