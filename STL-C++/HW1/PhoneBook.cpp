#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <tuple>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Person.h"
#include "PhoneNumber.h"
#include "PhoneBook.h"

PhoneBook::PhoneBook(std::ifstream& file) 
{
	Person person;
	PhoneNumber phonenumber;
	std::string str;
		
	if (!file.good())
	{
		std::cout << "File not found!" << std::endl;
		system("pause");
	}
	if (file.is_open())
	{
		while (file) //?
		{
			std::getline(file, str,'\n'); //need to split sting and fill person and phonenumber 
			std::istringstream iss(str);
			iss >> person.Surname >> person.Firstname >> person.Secondname
				>> phonenumber.CountryCode >> phonenumber.CityCode >> phonenumber.Number >> phonenumber.AdditionalNumber;
			m_Book.emplace_back(std::pair(person, phonenumber));
			}
	}

	file.close();
};
	
PhoneBook::~PhoneBook() {};
	
	void PhoneBook::Add(Person& person, PhoneNumber& PN)  //used that method to fill book to test other methods
	{
		std::pair<Person, PhoneNumber> temp(person, PN);
		m_Book.push_back(temp);
	};

	void PhoneBook::SortByName()
	{
		std::sort(m_Book.begin(), m_Book.end(),
			[](std::pair<Person, PhoneNumber> person1, std::pair<Person, PhoneNumber> person2)
			{
				return person1.first < person2.first;
			});
	};

	void PhoneBook::SortByPhone()
	{
		std::sort(m_Book.begin(), m_Book.end(),
			[](std::pair<Person, PhoneNumber> person1, std::pair<Person, PhoneNumber> person2)
			{
				return person1.second < person2.second;
			});
	};

	std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const char* Surname) const
	{
		std::string answer = "";
		int32_t counter = 0;
		PhoneNumber tNumber;
		std::for_each(m_Book.begin(), m_Book.end(),
			[Surname, &counter, &tNumber](const std::pair<Person, PhoneNumber>& person) mutable
			{
				if (person.first.Surname == Surname)
				{
					counter++;
					tNumber = person.second;
				}
			}
		);
		if (counter == 1)
		{
			answer = "";
			return std::tuple<std::string, PhoneNumber>(answer, tNumber);
		}
		else if (counter > 1)
		{
			answer = "Found more than 1";
			std::memset(&tNumber, 0, sizeof(PhoneNumber));
			return std::tuple<std::string, PhoneNumber>(answer, tNumber);
		}
		else
		{
			answer = "not found";
			std::memset(&tNumber, 0, sizeof(PhoneNumber));
			return std::tuple<std::string, PhoneNumber>(answer, tNumber);
		}
	};

	void PhoneBook::ChangePhoneNumber(const Person& pers, const PhoneNumber& pn) 
	{
		std::pair<Person, PhoneNumber> tPerson(pers,pn);
		auto it = [pers](const std::pair<Person, PhoneNumber>& person) -> bool
		{
			return person.first == pers;
		};
		auto result = std::find_if(m_Book.begin(), m_Book.end(), it);
		if (result == m_Book.end())
		{
			std::cout << "not found" << std::endl;
		}
		else
		{			
			std::cout << "finded" << std::endl;
			//result = tPerson;
		}
	};


std::ostream& operator<< (std::ostream& out, PhoneBook& book)
{
	std::pair<Person, PhoneNumber> tPair;

	for(uint32_t i = 0; i < book.m_Book.size(); i++)
	{
		tPair = book.m_Book[i];
		out << tPair.first << " - " <<tPair.second << std::endl;
		
	}
	return out;
}


