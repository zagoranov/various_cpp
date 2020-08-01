#include <iostream>
#include <type_traits>

using namespace std;

template<typename...> using VoidT = void;


template<typename T, typename = VoidT<>>
struct IsDefConstructibleT : std::false_type {};

template<typename T>
struct IsDefConstructibleT<T, VoidT<decltype(T())>> : std::true_type {}; 

struct S{
S() = delete;
};

int main() {
    cout << "int - " << (IsDefConstructibleT<int>()?"yes":"no") << "\n";
    cout << "S - " << (IsDefConstructibleT<S>()?"yes":"no") << "\n";
    
    
    return 0;
}
