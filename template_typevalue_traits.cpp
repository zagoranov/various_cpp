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

template<>
struct AccTraits<float>{
    using AccT = double;
    static AccT constexpr zero = 0.;
};


class SumPolicy {
public:
    template<typename T1, typename T2> 
    static void accumulate(T1& total, T2 const& value) {
        total += value;
    }

};

template<typename T, typename Policy = SumPolicy, typename AT = AccTraits<T> >
auto accum(T const* beg, T const* end) {
    typename AT::AccT total = AccTraits<T>::zero;
    while(beg != end) {
        Policy::accumulate(total, *beg);
        ++beg;
    }
    return total;
};

int main() {
    
    int iarr[] = {1, 2, 3, 4, 5};
    std::cout << accum(iarr, iarr + 5) << std::endl;
    
    char carr[] = "12345";
    std::cout << accum(carr, carr + 5) << std::endl;
    
    float farr[] = {1.1, 2.0, 3.0, 4.0, 5.1};
    std::cout << accum(farr, farr + 5) << std::endl;
    
}
