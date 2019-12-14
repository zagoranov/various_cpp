
//--------------------------------------------------------------------------------
// all_of()

template<class... Args, class Predicate>
void AllOf(Args&&... args, Predicate predicate) {

	std::all_of(std::forward<Args>(args)..., predicate);

}

//--------------------------------------------------------------------------------
// cozy initializer

template<class... Args>
void Log(Args&&... args) {
	(std:cerr << ... << args) << '\n';
}
//--------------------------------------------------------------------------------
// Apply lambda to all members of tuple<> 
// auto f = [](int x, double y, double z) { return x + y + z; };
// auto t = std::make_tuple(30, 5.0, 1.6);  // std::tuple<int, double, double>
// auto res = apply(f, t); 

//Better new realzation
template<typename... Args>
void apply2(std::function<double(int, double, double)> N, Args&... args) {
    N(std::forward<Args>(args)...);
}

//Old poorer realization
template<std::size_t I = 0, typename F, typename... Tp, typename... Tp2>
auto apply(F func, std::tuple<> t, Tp2... args) -> decltype(F(args...))
{
    return func(args...);	
}
template<std::size_t I = 0, typename F, typename... Tp, typename... Tp2>
auto apply(F func, std::tuple<Tp...> t, Tp2... args) -> decltype(F(args...)) {
	apply<I + 1, F, Tp..., Tp2...>(func, t, std::get<I>(t), args...);
}
