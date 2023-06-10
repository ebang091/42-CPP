#include "Span.hpp"

int main() {

	std::cout << "------------------test start!---------------\n";
	std::cout << "------------------test1---------------\n";	
	try{
		Span span(6);
		span.addNumber(0);
		span.addNumber(1);
		span.addNumber(2);
		for(unsigned int i = 0 ; i < span.size(); i++)
			std::cout << span.getNum(i) << " ";
		std::cout << "\n";
		std::cout << "shortest "<<   span.shortestSpan() << std::endl;
		std::cout << "longest " << span.longestSpan() << std::endl;
	}
	catch (std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\n------------------test2---------------\n";
	try{
		Span span(10);
		for(int i = 0; i < 111; i++){
			span.addNumber(i);
		}
		for(unsigned int i = 0 ; i < span.size(); i++)
			std::cout << span.getNum(i) << " ";
		std::cout << "\n";
	}
	catch (std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n------------------test3---------------\n";
	try{
		srand(time(NULL));
		Span span(6);
		for(int i = 0; i < 6; i++){
			span.addNumber(rand() % 100);
		}
		for(unsigned int i = 0 ; i < span.size(); i++)
			std::cout << span.getNum(i) << " ";
		std::cout << "\n";
		std::cout << "shortest "<<   span.shortestSpan() << std::endl;
		std::cout << "longest " << span.longestSpan() << std::endl;
	}
	catch (std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}

	// std::cout << "\n------------------test4---------------\n";
	// try{
	// 	Span span(100000);
	// 	for(int i = 0; i < 10000; i++){
	// 		span.addNumber(i);
	// 	}
	// 	for(unsigned int i = 0 ; i < span.size(); i++)
	// 		std::cout << span.getNum(i) << " ";
	// }
	// catch (std::runtime_error &e){
	// 	std::cout << e.what() << std::endl;
	// }

    return 0;
}
