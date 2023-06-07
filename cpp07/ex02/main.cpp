#include "Array.hpp"

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

    std::cout << "\n-------------test3-------------\n";
    Array<Data> arr3(5);
    for(unsigned int i = 0; i < arr3.size(); i++){
        arr3[i].idx = i;
        arr3[i].num = i  *  10;
    }

    for(unsigned int i = 0; i < arr3.size(); i++){
        std::cout << arr3[i] << " ";
    }
    atexit(check);

}