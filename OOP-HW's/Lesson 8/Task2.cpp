//#include <iostream>
//#include <cstdint>
//
//class Ex
//{
//private:
//	double m_x = 0.0;
//public:
//	Ex(double x)
//	:m_x(x)
//	{}
//};
//
//class Bar
//{
//private:
//	int32_t m_y = 0;
//public:
//	Bar(int32_t y = 0)
//	:m_y(y)
//	{}
//	void set(int32_t a)
//	{
//		if ((m_y + a) > 100)
//		{
//			Ex exa(a * m_y);
//			throw &exa;
//		}
//		else
//		{
//			m_y = a;
//		}
//	}
//};
//
//
//int main()
//{
//	int32_t var = 1;
//	Bar bar;
//	try
//	{
//		while (var != 0)
//		{
//			std::cout << "input a number: " << std::endl;
//			std::cin >> var;
//			bar.set(var);
//		}
//		
//	}
//	catch(Ex* a)
//	{
//		std::cerr << "Error at memory location: " << a;
//	}
//
//
//
//	return 1;
//}