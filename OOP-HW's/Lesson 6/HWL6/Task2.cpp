#include <iostream>
#include <cstdint>


std::ostream& endll(std::ostream& stream)
{
	stream.put('\n');
	stream.put('\n');
	stream.flush();
	return stream;
}


//int main()
//{
//	std::cout << 5 << endll;
//	std::cout << 5;
//
//	return 1;
//}