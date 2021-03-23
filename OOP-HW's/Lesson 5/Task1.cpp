#include <iostream>
#include <cstdint>

template <class T>

 class Pair1
{
	private:
		 T m_First;
		 T m_Second;
	public:
		Pair1<T>(T first, T second)
			:m_First(first),m_Second(second)
		{}
		T First() const { return m_First; }
		T Second() const { return m_Second; }

};


//int main()
//{
//	Pair1<int32_t> p1(5, 4);
//	Pair1<double> p2(6.4, 9.2);
//	std::cout << "pair: " << p1.First() << ' ' << p1.Second() << '\n';
//	std::cout << "pair: " << p2.First() << ' ' << p2.Second() << '\n';
//	return 0;
//}

