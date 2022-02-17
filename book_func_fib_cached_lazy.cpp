// https://www.manning.com/books/functional-programming-in-c-plus-plus

// 6 Lazy evaluation


#include <iostream>
#include <map>

unsigned int fib(unsigned int n) {
    return n == 0 ? 0 :
           n == 1 ? 1 :
                    fib(n - 1) + fib(n - 2);
}

template <typename T>
auto make_memorized(T (*f)(T n)) {
    std::map<T, T> cache;    

    return [f, cache](T n) mutable -> T
    { 
        const auto cached = cache.find(n);
        if (cached == cache.end()) {
            auto result = f(n);
            cache[result] = result;    
            return result;    

        } else {
            return cached->second;    
        }
    };
}



int main() {
    auto fibmemo = make_memorized(fib);
    std::cout << "fib( 20 ) = " << fibmemo(20) << std::endl;    
    std::cout << "fib( 15 ) = " << fibmemo(15) << std::endl;

}
