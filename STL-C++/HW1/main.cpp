#include <cstdint>
#include <iostream>
#include "PhoneBook.h"

int main()
{
	std::ifstream BookFile("PhoneBook.txt");
	PhoneBook book(BookFile);

	std::cout << book;
	std::cout << "\n-------------sorted by name--------------\n" << std::endl;
	book.SortByName();
	std::cout << book;

	std::cout << "\n-------------sorted by number------------\n" << std::endl;
	book.SortByPhone();
	std::cout << book;

	std::cout << "\n--------------GetPhoneNumber-------------\n" << std::endl;
	auto print_phone_number = [book](const char* Surname) 
	{
		std::tuple<std::string, PhoneNumber> pp(book.GetPhoneNumber(Surname));
		std::cout << std::get<0>(pp) << " " << std::get<1>(pp) << std::endl;	
	};
	print_phone_number("Zaitsev");

	std::cout << "\n------------ChangePhoneNumber------------\n" << std::endl;
	Person PS{ "Zaitsev","Zakhar","Artemovich" };
	
	book.ChangePhoneNumber(PS, PhoneNumber{7, 123,15344458});
		print_phone_number("Zaitsev");

	return 0;
}