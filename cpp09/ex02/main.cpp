#include "PmergeMe.hpp"

std::vector <long long> origin;
/*

sort(1)
5 3 1 9 11 7

left 5 3 1 
right 9 11 7


sort(2) : left 5 3 1
	left 5 
	right 3 1

	left = 5
	right = {sort(3) left = 3, right = 1
			merge (left, right)
			{3, 1}	}

	merge({5}, {3, 1})
	


*/
std::vector<long long> algorithm(std::vector <long long> origin){
	std::vector<node> temp;
	bool isOdd = false;
	long long left;
	long long min, max;
	for(int i = 0; i < origin.size() - 1; i+=2){
		max = origin[i] > origin[i+1] ? origin[i] : origin[i+1];
		min = origin[i] < origin[i+1] ? origin[i] : origin[i+1];
		temp.push_back(std::make_pair(max, min));
	}
	if(origin.size() % 2 == 1){
		isOdd = true;
		left = origin[origin.size()-1];
	}




	
	//0   2   4 5 6
	//1 2 3 4 5	6

}

int main(int argc, char **argv){

	if(argc != 2){
		std::cout << "usage: PmergeMe [args]";
		return 1;
	}
	std::string str;
	for(int i = 1; i < argc; i++){
		//string으로 , 그리고 공백을 기준으로 숫자들이 입력된다. 
		str = argv[i];
		int j = 0;
		int whitespaceNum = 0;
		while(j < str.size()){
			std::string strNum;
			whitespaceNum = 0;
			while(j + whitespaceNum < str.size() && str[j + whitespaceNum++] == ' ');
			j += whitespaceNum;
			strNum = "":
			while(j < str.size() && std::isdigit(str[j])){
				strNum += str[j];
			}
			long long num = std::strtoll(strNum.c_str(), NULL);
			origin.push_back(num);
		}
	}

	std::cout << "Before:	";
	for(int i = 0; i < origin.size(); i++){
		std::cout << origin[i] << " ";
	}
	std::cout << std::endl;

	std::vector<long long> ans = algorithm(origin);
	std::cout << "After:	";
	for(int i = 0; i < ans.size(); i++){
		std::cout << ans[i] << " ";
	}
	std::cout << std::endl;



}