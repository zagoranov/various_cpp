#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

namespace
{
	struct payload
	{
		float weight, volume;
	};

	class basic_truck
	{
	public:
		virtual bool fits(const payload& p) const noexcept = 0;
		virtual string print() const = 0;
		virtual ~basic_truck() { }
	};

	class p1_truck : public basic_truck
	{
	public:
		explicit p1_truck(const float weight) noexcept : m_weight(weight) { }
		bool fits(const payload& p) const noexcept override
		{
			return p.weight <= m_weight;
		}

		string print() const override
		{
			return "weight: "s + to_string(m_weight);
		}

	private:
		float m_weight;
	};

	class p2_truck : public basic_truck
	{
	public:
		explicit p2_truck(const float weight, const float volume) noexcept :
			m_weight(weight),
			m_volume(volume)
		{

		}

		bool fits(const payload& p) const noexcept override
		{
			return p.weight <= m_weight && p.volume <= m_volume;
		}

		string print() const override
		{
			return "weight: "s + to_string(m_weight) + ", volume: "s + to_string(m_volume);
		}

	private:
		float m_weight, m_volume;
	};
}

int main(int, char**)
{
	vector<shared_ptr<basic_truck>> test
	{
		make_shared<p1_truck>(5),
		make_shared<p2_truck>(7, 15),
		make_shared<p1_truck>(2),
		make_shared<p1_truck>(8),
		make_shared<p2_truck>(2, 5),
		make_shared<p2_truck>(9, 8),
		make_shared<p2_truck>(17, 1)
	};

	payload p { 3, 7 };

	test.erase(remove_if(begin(test), end(test), [&p](const auto& pt) { return !pt->fits(p); }), end(test));

	cout << "Result:" << endl;
	for (const auto& t : test)
	{
		cout << t->print() << endl;
	}

	return 0;
}
