#pragma once
#include <iostream>
#include <cstdint>
#include <tuple>
#include <string>

extern struct Person
{
	std::string Surname;
	std::string Firstname;
	std::string Secondname{};

	friend std::ostream& operator<< (std::ostream& out, const Person& temp);
	friend bool operator< (const Person& Left, const Person& Right);
	friend bool operator== (const Person& Left, const Person& Right);
};