#include <iostream>
#include <fstream>
#include <cstdint>
#include <tuple>
#include <string>
#include <vector>
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
		PhoneNumber pnumber;
		if (file.is_open())
		{
			
			
		}

		file.close();
	}

	~PhoneBook(){}
	
	friend std::ostream& operator<< (std::ostream& out, PhoneBook& book);
};

std::ostream& operator<< (std::ostream& out, PhoneBook& book)
{
	//out << book.mBook.first << " - " << book.mBook.second;
	return out;
}

int main()
{
	std::ifstream BookFile("PhoneBook.txt");
	PhoneBook book(BookFile);

	return 0;
}