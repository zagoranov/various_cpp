#include <iostream>

template<typename T>
struct AccTraits;

template<>
struct AccTraits<char>{
    using AccT = int;
    static AccT const zero = 0;
};


template<>
struct AccTraits<int>{
    using AccT = long;
    static AccT const zero = 0;
};


template<typename T>
auto accum(T const* beg, T const* end) {
    using AccType = typename AccTraits<T>::AccT;
    AccType total = AccTraits<T>::zero;
    while(beg != end) {
        total += *beg;
        ++beg;
    }
    return total;
};

int main() {
    
    int iarr[] = {1,2,3,4,5};
    std::cout << accum(iarr, iarr + 5) << std::endl;
    
    char carr[] = "12345";
    std::cout << accum(carr, carr + 5);
    
}
