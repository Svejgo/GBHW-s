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



template<class T>
class StringValuePair : public Pair<std::string, T> 
{
protected:
	std::string m_First;
	T m_Second;
public:
	StringValuePair(std::string first, T second)
	:Pair<std::string, T>(first,second)
	{}
};


int main()
{
	StringValuePair<int32_t> svp("Amazing", 7);
	std::cout << "Pair: " << svp.First() << ' ' << svp.Second() << '\n';
	return 0;
}