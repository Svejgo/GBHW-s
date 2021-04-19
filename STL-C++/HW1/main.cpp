#include <cstdint>
#include <iostream>
#include "PhoneBook.h"

int main()
{
	std::ifstream BookFile("PhoneBook.txt");
	PhoneBook book(BookFile);

	//-----------------just for test other methods
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
	//--------------------	

	std::cout << book;
	std::cout << "-------------sorted by name--------------" << std::endl;
	book.SortByName();
	std::cout << book;

	std::cout << "-------------sorted by number------------" << std::endl;
	book.SortByPhone();
	std::cout << book;

	std::cout << "--------------GetPhoneNumber-------------" << std::endl;
	auto print_phone_number = [book](const char* Surname) 
	{
		std::tuple<std::string, PhoneNumber> pp(book.GetPhoneNumber(Surname));
		std::cout << std::get<0>(pp) << " " << std::get<1>(pp) << std::endl;	
	};
	print_phone_number("Zaitsev");

																			

	return 0;
}