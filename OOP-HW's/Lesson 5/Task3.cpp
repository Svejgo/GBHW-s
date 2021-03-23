#include <iostream>
#include <cstdint>
#include <string>


template <class T, class S>


class Pair
{
protected:
	T m_First;
	S m_Second; 
public:
	Pair<T, S>(T first, S second)
		: m_First(first), m_Second(second)
	{}
	 T First() const { return m_First; }
	 S Second() const { return m_Second; }

};

//template<class T>
//class StringValuePair : Pair  // << вот здесь по€вл€лась ошибка C2955 - 'Pair': use of class template requires template argument list.    сожалению € не смог разобратьс€, как именно указать аргументы
//{
//protected:
//	std::string m_First;
//	T m_Second;
//public:
//	StringValuePair<T>(std::string first, T second)
//	:Pair<std::string, T>(first,second)
//	{}
//	std::string First() const { return m_First; }
//	T Second() const { return m_Second; }
//
//};


//int main()
//{
//	StringValuePair svp("Amazing", 7);
//	std::cout << "Pair: " << svp.First() << ' ' << svp.Second() << '\n';
//	return 0;
//}