#include <iostream>
#include <cstdint>
#include <tuple>
#include <string>
#include "Person.h"

//_Persona Person;

std::ostream& operator<< (std::ostream& out, const Person& temp)
{
	out << temp.Surname << ' ' << temp.Firstname;
		if (!(temp.Secondname == "-"))
		{
			out << ' ' << temp.Secondname;
		}
	return out;
}

bool operator<(const Person& Left, const Person& Right)
{
	return tie(Left.Surname, Left.Firstname, Left.Secondname) < tie(Right.Surname, Right.Firstname, Right.Secondname);
}

bool operator== (const Person& Left, const Person& Right)
{
	return tie(Left.Surname, Left.Firstname, Left.Secondname) == tie(Right.Surname, Right.Firstname, Right.Secondname);
}

//int main()
//{
//	Person John { "Malkovich", "John", "Seregutskii" };
//	Person John2 { "Malkovich", "John", "Seregutskii" };
//	std::cout << John << std::endl;
//	Person Johan{ "Zalcer", "Johan" };
//	std::cout << Johan << std::endl;
//	std::cout << std::boolalpha << (John < Johan) << std::endl;
//	std::cout << std::boolalpha << (John == Johan) << std::endl;
//	std::cout << std::boolalpha << (John == John2) << std::endl;
//
//	return 1;
//}