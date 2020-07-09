#include <iostream>

template<typename T>
struct AccTraits;

template<>
struct AccTraits<char>{
    using AccT = int;
};


template<>
struct AccTraits<int>{
    using AccT = long;
};


template<typename T>
auto accum(T const* beg, T const* end) {
    using AccType = typename AccTraits<T>::AccT;
    AccType total{};
    while(beg != end) {
        total += *beg;
        ++beg;
    }
    return total;
};

int main() {
    
    int iarr[] = {1,2,3,4,5};
    std::cout << accum(iarr, iarr + 5) << std::endl;
    
    char carr[] = "123456";
    std::cout << accum(carr, carr);
    
}
