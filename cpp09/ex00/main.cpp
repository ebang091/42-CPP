#include "BitcoinExchange.hpp"

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







int main(int argc, char **argv){
    if(argc != 2){
        std::cout << "usage : ./btc [input filename]\n";
        return 1;
    }
    try
    {
        BitcoinExchange::loadData();
        // BitcoinExchange::checkData();

        std::string filename = argv[1];
        // BitcoinExchange::parseInputDataAndPrintOutput(argv[1]);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
        return 1;
    }

    // std::vector<std::pair<int, double> >::iterator  it;
    // 2012-11-03,10.62
    // it = std::upper_bound(data.begin(), data.end(), std::pair<int, double>(20121102, 0), cmp);
    // std::cout << (--it)->first << " " << it->second << "\n";
    // for(it = data.begin(); it != data.end(); it++){
    //     std::cout << it->first << " " << it->second << "\n";
    // }
    // std::cout << data.size(); 
    
}