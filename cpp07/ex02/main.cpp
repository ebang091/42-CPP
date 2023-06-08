#include "Array.hpp"
#include <cstdlib>

typedef struct data  Data;
struct data{
    int idx;
    int num;
};

std::ostream &operator<<(std::ostream &os, const Data &d){
    os << "[" << d.idx  << "] : " <<  d.num << "\n";
    return os;
}

void check(){
    system("leaks Array");
}


int main(){
    
    {
        std::cout << "-------------test1-------------\n";
        Array<int> arr1(5);
        for(unsigned int i = 0; i < arr1.size(); i++){
            arr1[i] = static_cast<int>(i + 1);
        }

        for(unsigned int i = 0; i < arr1.size(); i++){
            std::cout << arr1[i] << " ";
        }
    
    
    
        std::cout << "\n-------------test2-------------\n";
        Array<int> arr2(arr1);
        std::cout << "arr1: \n";
        for(unsigned int i = 0; i < arr1.size(); i++){
            std::cout << arr1[i] << " ";
        }
        std::cout << "\narr2: \n";
        for(unsigned int i = 0; i < arr1.size(); i++){
            std::cout << arr2[i] << " ";
        }


        Array<int> arrCopy;
        arrCopy = arr2;
        std::cout << "\narrCopy: \n";
        for(unsigned int i= 0; i < arr1.size(); i++){
            std::cout << arrCopy[i] << " ";
        }
        std::cout << std::endl;

        // try{
        //     Array<double> arrDouble;
        //     arrDouble = arr2;
        //     std::cout << "\narrDouble: \n";
        //     for(unsigned int i= 0; i < arr1.size(); i++){
        //         std::cout << arrCopy[i] << " ";
        //     }


        // }
        // catch(std::exception & e){
        //     std::cerr << e.what();
        // }
        std::cout << std::endl;

    }


    {
        std::cout << "\n-------------test3-------------\n";
        Array<Data> arr3(5);
        for(unsigned int i = 0; i < arr3.size(); i++){
            arr3[i].idx = i;
            arr3[i].num = i  *  10;
        }

        for(unsigned int i = 0; i < arr3.size(); i++){
            std::cout << arr3[i] << " ";
        }
    }

    {
        std::cout << "\n-------------test4-------------\n";
        Array<char> arr4(10);
        std::cout << &arr4 << "\n";
        std::cout << arr4[0] << "\n";
    }   

    {

        //const 는 사용불가: 선언과(생성자) 동시에 초기화가 불가능.    new T[n] 으로 할당 후 값 넣는 것만 가능.
        srand(time(NULL));
        std::cout << "\n-------------test5-------------\n";
        Array<int> arr5(10);

        for(unsigned int i = 0; i < 10; i++){
            arr5[i] = rand();
        }

           for(unsigned int i = 0; i < 10; i++){
            std::cout << "[" << i << "]: " << arr5[i] << " \n";
        }
        
        try{
                arr5[-1] = -1;
        }
        catch(std::exception &e){
            std::cerr << e.what() ;
        }

        std::cout << std::endl;
    }
    // atexit(check);

}