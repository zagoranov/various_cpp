
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

	//	Inserting to start
template<int H, typename T>
struct IntCons;

template<int H, int... T>
struct IntCons<H, IntList<T...>> {
	using type = IntList<H, T...>;
};
using L1 = IntList<2,3,4>; 
using L2 = IntCons<1, L1>::type;   // IntList<1,2,3,4>

	//  List Generator
template <int N, class Collection = IntList<>>
struct Generate
{
    static const int Length = N;
    using type = typename IntCons<typename Generate<N - 1>::type, Generate<N-1>::Length >::type;
};

template<>
struct Generate<0>
{
    static const int Length = 0;
    using type = IntList<>;
};
using L3 = Generate<5>::type;      // IntList<0,1,2,3,4>

main() {


}





