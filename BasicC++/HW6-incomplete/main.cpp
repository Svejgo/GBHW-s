#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdint.h> //start to use this library! i hope i'll doing right
#include <vector>


int main() {
	
	
	//Task1
	std::ofstream FirstOut;
	std::ofstream SecondOut;
	
	FirstOut.open(".\\1.txt");
	if(FirstOut.is_open())
	{
		int32_t counter = 0;
		for (counter = 1; counter < 50; counter++)
		FirstOut << char('a' + rand() % ('z' - 'a'));
	}
	FirstOut.close();
	
	SecondOut.open(".\\2.txt");
	if(SecondOut.is_open())
	{
		int32_t counter = 0;
		for (counter = 1; counter < 50; counter++)
		SecondOut << char('a' + rand() % ('z' - 'a'));
	}
	SecondOut.close();
	
	//Task2
	std::ofstream ThirdOut;
	std::ifstream FirstRead(".\\1.txt");
	std::ifstream SecondRead(".\\2.txt");
	
	std::vector<std::string> Buffer;
	std::string ThirdFile = "";
	
	while(!FirstRead.eof())
	{
		std::getline(FirstRead,ThirdFile);
		Buffer.push_back(ThirdFile);
	}
	while(!SecondRead.eof())
	{
		std::getline(SecondRead,ThirdFile);
		Buffer.push_back(ThirdFile);
	}
	
	
	uint32_t BufferSize = Buffer.size();
		
	ThirdOut.open(".\\3.txt");
	if(ThirdOut.is_open())
	{
		for(int32_t counter = 0; counter < BufferSize; counter++)
		{
			ThirdOut << Buffer[counter];
		}
	}
	ThirdOut.close();


	return 0;
}
