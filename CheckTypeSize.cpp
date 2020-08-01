#include <iostream>
#include <type_traits>
#include <vector>


template<typename T>
struct RParam {
using Type = std::conditional< (sizeof(T) <= 2 * sizeof(void*)),
    T, T const& >::type;
};


int main() {
    std::cout << "char: " << std::is_same< RParam<char>::Type, char >::value << "\n";
    std::cout << "int: " << std::is_same< RParam<int>::Type, int >::value << "\n";   
    
    std::cout << "std::vector<int>: " << std::is_same< RParam< std::vector<int> >::Type, std::vector<int> >::value << "\n";
    std::cout << "std::vector<int> const &: " << std::is_same< RParam<std::vector<int>>::Type, std::vector<int> const &>::value << "\n";
    return 0;
}
