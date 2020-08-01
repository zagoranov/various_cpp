#include <iostream>
#include <type_traits>
#include <utility>
using namespace std;

template<typename, typename, typename = std::void_t<>>
struct CanMinusT : std::false_type {};

template<typename T1, typename T2 >
struct CanMinusT<T1, T2, std::void_t< decltype(declval<T1>() - declval<T2>()) > > : std::true_type {};

struct S{
S() = delete;
};

int main() {
    cout << "int - int: " << ( CanMinusT<int, int>()?"yes":"no" ) << "\n";
    cout << "int - S: "   << ( CanMinusT<int, S>()?"yes":"no" ) << "\n";
    return 0;
}
