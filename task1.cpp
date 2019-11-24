#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace
{
	struct truck {
		float weight, volume;
	};

	constexpr bool operator<(const truck& a, const truck& b) noexcept {
		return a.weight != b.weight ?  a.weight < b.weight :a.volume < b.volume;
	}

	template<typename Ch> basic_ostream<Ch>& operator<<(basic_ostream<Ch>& s, const truck& t) {
		s << "weight: " << t.weight << ", volume: " << t.volume;
		return s;
	}
}

int main(int, char**)
{
	vector<truck> test
	{
		{ 5, 12 },
		{ 4, 16 },
		{ 4, 12 },
		{ 12, 6 },
		{ 1, 23 }
	};

	sort(begin(test), end(test), [](const auto& a, const auto& b) { return !(a < b); });

	cout << "Result:" << endl;
	for (const auto& t : test)
	{
		cout << t << endl;
	}

	return 0;
}
