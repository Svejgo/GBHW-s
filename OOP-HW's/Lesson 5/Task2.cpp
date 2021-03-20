#include <iostream>
#include <cstdint>

template <typename T, typename S>


class Pair
{
private:
	T m_First;
	S m_Second;
public:
	Pair<T, S>(T first, S second)
		: m_First(first), m_Second(second)
	{}
	T First() const { return m_First; }
	S Second() const { return m_Second; }

};


int main()
{
	Pair<int32_t, double> p1(6, 7.8);
	Pair<double, int32_t> p2(3.4, 5);

	std::cout << "Pair: " << p1.First() << ' ' << p1.Second() << std::endl;
	std::cout << "Pair: " << p2.First() << ' ' << p2.Second() << std::endl;

	return 0;
}

