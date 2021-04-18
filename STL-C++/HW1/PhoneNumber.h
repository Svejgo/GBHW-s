#pragma once

struct PhoneNumber
{
	//код страны, код города, номер телефона, добавочный номер
	int32_t CountryCode{};
	int32_t CityCode{};
	int32_t Number{};
	int32_t AdditionalNumber{};
	friend std::ostream& operator<< (std::ostream& out, const PhoneNumber& temp);
};