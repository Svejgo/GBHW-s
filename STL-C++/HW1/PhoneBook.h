#pragma once
#include <iostream>
#include <fstream>
#include <cstdint>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>
#include "Person.h"
#include "PhoneNumber.h"

class PhoneBook
{
private:
	std::vector<std::pair<Person, PhoneNumber>> m_Book{};

public:

	PhoneBook(std::ifstream& file);

	~PhoneBook();

	void Add(Person& person, PhoneNumber& PN);

	void SortByName();
	void SortByPhone();
	void ChangePhoneNumber(Person& person, PhoneNumber& phonenumber);

	std::tuple<std::string, PhoneNumber> GetPhoneNumber(const char* Surname) const;
	

	friend std::ostream& operator<< (std::ostream& out, PhoneBook& book);
};

