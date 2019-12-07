
// struct declaration
template<int... Types>
struct IntList;

// default specification
template<int H, int... T>
struct IntList<H, T...> {
    static const int Head = H;
    using Tail = IntList<T...>;
	static const int Length = 1 + sizeof...(T);
};
// empty specification
template<>
struct IntList<> {};


// Longer Length calculation realization
template<typename TL>
struct Length {
    static const int value = 1 + Length<typename TL::Tail>::value;
};
//  size calculation for empty
template<>
struct Length<IntList<>> {
    static const int value = 0;
};


using primes = IntList<2,3,5,7,11,13>;
constexpr int head = primes::Head;
using odd_primes = primes::Tail;

constexpr size_t len = Length<primes>::value;


main() {


}





