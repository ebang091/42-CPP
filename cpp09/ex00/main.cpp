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

//
int strDateToInt(std::string strDate){
    std::string ret;
    //string YYYY-MM-DD 형태의 날짜를 int형으로 바꾸어 반환한다.
    // .     0123456789
    ret.assign(strDate.c_str(), 0, 4);
    ret.append(strDate.c_str(), 5, 2);
    ret.append(strDate.c_str(), 8, 2);
    int intDate = static_cast<int>(strtod(ret.c_str(), NULL));
    return intDate;
}

bool save_database(std::vector<std::pair<int, double> > &data){
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
    char exchangeRate[128];
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
            str.copy(exchangeRate, str.size() - 1 , pos+1);
            std::string strDate = date;
            int intDate = strDateToInt(strDate);
            std::string strExchangeRate = exchangeRate;
            
            double dExchangeRate = strtod(strExchangeRate.c_str(), NULL);
            data.push_back(std::pair<int, double>(intDate, dExchangeRate));
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

bool cmp(std::pair<int, double>  a, std::pair<int, double> b){
    if(a.first < b.first)
        return true;
    return false;
}


int main(int argc, char **argv){
    if(argc != 2){
        std::cout << "usage : ./btc [input filename]\n";
        return 1;
    }

    //dataSaver
    std::vector<std::pair<int, double> >  data;
    if(save_database(data)){
        std::cout << "reading database failed.\n";
        return 1;
    }
    sort(data.begin(), data.end(), cmp);


    std::vector<std::pair<int, double> >::iterator  it;
    // 2012-11-03,10.62
    it = std::upper_bound(data.begin(), data.end(), std::pair<int, double>(20121102, 0), cmp);
    std::cout << (--it)->first << " " << it->second << "\n";
    // for(it = data.begin(); it != data.end(); it++){
    //     std::cout << it->first << " " << it->second << "\n";
    // }
    // std::cout << data.size(); 
    std::ifstream ifs;
    std::string filename = argv[1];
    ifs.open(filename);
    if(ifs.rdstate()){
        std::cout << "error: wrong file\n";
        ifs.close();
        return 1;
    }
}