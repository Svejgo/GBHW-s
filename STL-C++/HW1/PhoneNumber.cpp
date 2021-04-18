#include <iostream>
#include <cstdint>
#include <vector>
#include <tuple>
#include <string>
#pragma once

struct PhoneNumber
{
	//код страны, код города, номер телефона, добавочный номер
	int32_t CountryCode;
	int32_t CityCode;
	int32_t Number;
	int32_t AdditionalNumber{};
	friend std::ostream& operator<< (std::ostream& out, const PhoneNumber& temp);
};

std::ostream& operator<< (std::ostream& stream, const PhoneNumber& temp)
{
	stream << "+" << temp.CountryCode << "(" << temp.CityCode << ")" << temp.Number;
	
	if(temp.AdditionalNumber)
	stream << " " << temp.AdditionalNumber;

	return stream;
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