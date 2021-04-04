//#include <iostream>
//#include <cstdint>
//
//
//
//template <typename T>
//const T& Div(const T& a, const T& b)
//{
//	if (b == 0)
//	{
//		throw "Division by zero!";
//	}
//	else
//	{
//		return a / b;
//	}
//}


//int main()
//{ 
//	int32_t a = 30;
//	int32_t b = 3;
//	int32_t c = 0;
//
//	for (; b > -1; --b) 
//	{
//		std::cout << a << " divided by " << b << " equal = ";
//		try
//		{
//			c = Div(a, b);
//			std::cout <<  c << std::endl;
//		}
//		catch (const char* a)
//		{
//			std::cerr << "Error: " << a << std::endl;
//		}
//	}
//
//	return 0;
//}