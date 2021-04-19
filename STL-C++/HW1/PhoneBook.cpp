#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <tuple>
#include <string>
#include <vector>
#include <any>
#include "Person.h"
#include "PhoneNumber.h"

class PhoneBook
{
private:
	std::vector<std::pair<Person, PhoneNumber>> mBook{};

public:
	PhoneBook(Person& person, PhoneNumber& PN)
	{
		std::pair<Person,PhoneNumber> temp(person, PN);
		mBook.push_back(temp);
	}
	PhoneBook(std::ifstream& file)
	{
		Person person;
		PhoneNumber phonenumber;
		std::string str;
		int32_t i = 0;
		if (file.is_open())
		{
			while (i < 5)
			{
				file >> person.Surname >> person.Firstname >> person.Secondname
					>> phonenumber.CountryCode >> phonenumber.CityCode >> phonenumber.Number >> phonenumber.AdditionalNumber;

				mBook.emplace_back(std::pair(person, phonenumber));
				//while (std::getline(file, str)){}
				i++;
			}
		}

		file.close();
	}
	
	~PhoneBook(){}
	
	friend std::ostream& operator<< (std::ostream& out, PhoneBook& book);
};

std::ostream& operator<< (std::ostream& out, PhoneBook& book)
{
	std::pair<Person, PhoneNumber> tempPair;

	for(auto n : book.mBook)
	{
		tempPair = n;
		out << n.first << " - " << n.second;
		return out;
	}
	//out << book.mBook.first << " - " << book.mBook.second;
}

int main()
{
	std::ifstream BookFile("PhoneBook.txt");
	PhoneBook book(BookFile);
	std::cout << book;

	return 0;
}