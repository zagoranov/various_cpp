#include <iostream>
#include <type_traits>

using namespace std;


template<typename T>
struct IsDefConstructibleHelper {

private:
    template<typename U, typename = decltype(U())>
    static std::true_type test(void*);
    
    template<typename>
    static std::false_type test(...);

public:
    using Type = decltype(test<T>(nullptr));
};

template<typename T>
struct IsDefConstructibleT : IsDefConstructibleHelper<T>::Type {}; 

struct S{
S() = delete;
};


int main() {
    cout << "int - " << (IsDefConstructibleT<int>()?"yes":"no") << "\n";
    cout << "S - " << (IsDefConstructibleT<S>()?"yes":"no") << "\n";
    
    
    return 0;
}
