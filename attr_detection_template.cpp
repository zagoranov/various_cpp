// Strange task of getting signature of not existing function
// The attributes, that added to Bind will be skipped in new func signature
// https://stackoverflow.com/questions/65404162/why-this-c-template-code-got-expected-before-token-error/65405104

#include <type_traits>


template<typename T>
struct GetSignature {
  using signature = typename T::signature;
};

template<typename R>
struct GetSignature<R(void)> {
  template<typename... Args>
  struct Bind {
    using signature = R(void);
  };  
};

template<typename R, typename Arg, typename... Args>
struct GetSignature<R(Arg, Args...)> {
  template<typename... BArgs> struct Bind;

  template<typename BArg, typename... BArgs>
  struct Bind<BArg, BArgs...> {
    static_assert(std::is_same<Arg, BArg>::value);
    using signature = typename GetSignature<R(Args...)>::template Bind<BArgs...>::signature;
  };  

  template<typename BArg>
  struct Bind<BArg> {
    using signature = R(Args...);
  };  
};


int func(bool, double, int, char) { return 1; };

int main() {
   GetSignature<decltype (func)>::Bind<bool, double>::signature* qq;  // result: int(*)(int, char)
  return 0;
}
