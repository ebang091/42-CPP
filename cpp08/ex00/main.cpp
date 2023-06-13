#include "easyfind.hpp"

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    try {
        std::vector::iterator it = easyfind(numbers, 3);
        std::cout << "Value found at index: " << std::distance(numbers.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    try {
        std::vector::iterator it = easyfind(numbers, 6);
        std::cout << "Value found at index: " << std::distance(numbers.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}