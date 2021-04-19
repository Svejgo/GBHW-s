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

	PhoneBook(std::ifstream& file)
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
			while (std::getline(file,str))
			{
				file >> person.Surname >> person.Firstname >> person.Secondname
					>> phonenumber.CountryCode >> phonenumber.CityCode >> phonenumber.Number >> phonenumber.AdditionalNumber;

				m_Book.emplace_back(std::pair(person, phonenumber));
			}
		}

		file.close();
	}
	
	~PhoneBook(){}
	
	void Add(Person& person, PhoneNumber& PN)
	{
		std::pair<Person, PhoneNumber> temp(person, PN);
		m_Book.push_back(temp);
	}

	void SortByName()
	{
		std::sort(m_Book.begin(), m_Book.end(),
			[](std::pair<Person, PhoneNumber> person1, std::pair<Person, PhoneNumber> person2)
			{
				return person1.first < person2.first;
			});
	}
	void SortByPhone()
	{
		std::sort(m_Book.begin(), m_Book.end(),
			[](std::pair<Person, PhoneNumber> person1, std::pair<Person, PhoneNumber> person2)
			{
				return person1.second < person2.second;
			});
	}

	std::tuple<std::string, PhoneNumber> GetPhoneNumber(std::string& Surname) const
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
			return std::tuple<std::string, PhoneNumber>(answer,tNumber);
		}
		else
		{  
			answer = "not found";
			std::memset(&tNumber, 0, sizeof(PhoneNumber));
			return std::tuple<std::string, PhoneNumber>(answer, tNumber);
		}
	}



	friend std::ostream& operator<< (std::ostream& out, PhoneBook& book);
};

std::ostream& operator<< (std::ostream& out, PhoneBook& book)
{
	std::pair<Person, PhoneNumber> tPair;

	for(uint32_t i = 0; i < book.m_Book.size(); i++)
	{
		tPair = book.m_Book[i];
		out <<tPair.first << " - " << tPair.second << std::endl;
		
	}
	return out;
	//out << book.mBook.first << " - " << book.mBook.second;
}

int main()
{
	std::ifstream BookFile("PhoneBook.txt");
	PhoneBook book(BookFile);
	//PhoneBook book;
	//Person John{ "Surname", "Name", "Lastname" };
	//Person Tim{ "Dag", "Tim", "Osuyhhtin" };
	//Person Sim{ "Sag", "Sim", "Sstiiin" };
	//Person Dim{ "Dag", "Dim", "Dsuuutin" };
	//Person Lim{ "Lag", "Lim", "Lsjtin" };
	//PhoneNumber pn1{ +7,913,5920092 };
	//PhoneNumber pn2{ +8,222,5555555,77 };
	//PhoneNumber pn3{ +7,111,3334488 };
	//PhoneNumber pn4{ +1,391,2050048 };
	//PhoneNumber pn5{ +99,391,2050048 };
	//

	//book.Add(John, pn1);
	//book.Add(Tim, pn2);
	//book.Add(Sim, pn3);
	//book.Add(Dim, pn4);
	//book.Add(Lim, pn5);
		

	std::cout << book;
	std::cout << "-------------sorted by name--------------" << std::endl;
	book.SortByName();
	std::cout << book;
	std::cout << "-------------sorted by phone-------------" << std::endl;
	book.SortByPhone();
	std::cout << book;
	std::string FindPerson = "Zaitsev";
	std::cout << FindPerson << std::endl;
	
	std::tuple<std::string, PhoneNumber> pp(book.GetPhoneNumber(FindPerson));
	std::cout << std::get<0>(pp) << " " << std::get<1>(pp) << std::endl;

	//std::tuple<std::string, PhoneNumber> pp(book.GetPhoneNumber(FindPerson));
	//std::cout << std::get<0>(pp) << " " << std::get<1>(pp) << std::endl;
	


	return 0;
}