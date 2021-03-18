#include <iostream>
#include <fstream>
#include <vector>
#include <stdint.h>
#include <cstring>






int main()
{
	//Task3
	//написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем файле.

std::ifstream ReadFile(".\\3.txt");

std::string Temp = "";
std::string WhatToFind = "";
	
std::cout << "Input what to find" << std::endl;
std::getline(std::cin, WhatToFind);
uint32_t WTFSize = WhatToFind.size();
	
	while(!ReadFile.eof())
	{
		std::getline(ReadFile,Temp);

	}
uint32_t TempSize = Temp.size();

std::cout << Temp.compare(WhatToFind);

//strcmp(Temp,WhatToFind);

	







  return 0;

}

