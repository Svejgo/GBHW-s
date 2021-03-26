//was copied that funcion from lesson 6 and just look how does it work.

#include <iostream>
#include <cstdint>
#include <cctype>

int32_t CheckTypeOfVar()
{
	int32_t a = 0;
	
	while (true)
	{
		std::cout << "Input int number: " << std::endl;
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else return a;
	}
	return 0;
}



//int main()
//{
//	std::cout << CheckTypeOfVar();
//
//
//	
//	return 1;
//}