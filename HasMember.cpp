#include <iostream>
#include <type_traits>

using namespace std;

#define DEFINE_HAS_MEMBER(Member)               \
  template<typename, typename = std::void_t<>>  \
  struct HasMemberT_##Member                    \
      : std::false_type {};                     \
  template<typename T>                          \
  struct HasMemberT_##Member<T, std::void_t< decltype(&T::Member)>>  \
      : std::true_type {};

                                                      
DEFINE_HAS_MEMBER(method_qq)
                                                      
                                                      
struct S{
 void method_qq() {};
};

int main() {
    cout << "int has member method_qq() ? " << ( HasMemberT_method_qq<int>::value?"yes":"no" ) << "\n";
    cout << "S has member method_qq() ? " << ( HasMemberT_method_qq<S>::value?"yes":"no" ) << "\n";
    return 0;
}
