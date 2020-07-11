#include <iostream>
#include <type_traits>

template<typename T>
void sImpl(T t, std::true_type){
    std::cout << "int realization"; 
}

template<typename T>
void sImpl(T t, std::false_type){
    std::cout << "other realization"; 
}

template<typename T>
void foo(T t){
    sImpl(t, std::is_same<T, int>{});
};


int main() {
    
    foo(42);
    
    foo("fortytwo");
    
}
