#include <iostream>
#include <cstdint>
#include <vector>
#include <tuple>
#include <string>
#include "PhoneNumber.h"



std::ostream& operator<< (std::ostream& stream, const PhoneNumber& temp)
{
	stream << "+" << temp.CountryCode << "(" << temp.CityCode << ")" << temp.Number;
	
	if(temp.AdditionalNumber)
	stream << " " << temp.AdditionalNumber;

	return stream;
}
 bool operator< (const PhoneNumber& Left, const PhoneNumber& Right)
{
	 return std::tie(Left.CountryCode, Left.CityCode, Left.Number, Left.AdditionalNumber) 
		 < std::tie(Right.CountryCode, Right.CityCode, Right.Number, Right.AdditionalNumber);
}

//
//int main()
//{
//	PhoneNumber PN{ 7,391,2050048 };
//	PhoneNumber PN1{ 7,391,2050048, 105 };
//	std::cout << PN << std::endl;
//	std::cout << PN1 << std::endl;
//
//	return 1;
//}