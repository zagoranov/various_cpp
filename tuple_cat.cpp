#include <iostream>
#include <tuple>
#include <list>
#include <utility>
#include <string>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;


template<typename T, typename ... Ts>
void print_args(ostream& os, const T& v, const Ts& ...vs) {
	os << v;
	(void)initializer_list<int>{((os << ", " << vs), 0)...};
}


template<typename ... Ts>
ostream& operator<<(ostream &os, const tuple<Ts...> &t) {
	auto capt_tup([&os](const auto &...xs) {
		print_args(os, xs...);
	});
	os << "(";
	apply(capt_tup, t);
	return os << ")";
}


template<typename T1, typename T2>
auto zip(const T1 &a, const T2 &b) {
	auto z ([](auto ...xs) {
		return [xs...](auto ...ys) {
			return tuple_cat(make_tuple(xs, ys) ...);
		};
	});
	return apply(apply(z, a), b);
}


int main() {
	auto student_desc (make_tuple("ID", "Name", "GPA"));
	auto student (make_tuple(123456, "John Doe", 3.7));
	
	cout << student_desc << endl << student << endl;
	
	cout << tuple_cat(student_desc, student);
	
	auto zipped (zip(student_desc, student));
	cout << zipped << endl;
	
}


