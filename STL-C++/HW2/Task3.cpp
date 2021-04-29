#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include "timer.h"

int32_t CountIfFind(const std::string& s)
{
	Timer timer("CountIf + find");
	std::vector<char> vowel{ 'À','à','Å','å','¨','¸','È','è','Î','î','Ó','ó','Û','û','Ý','ý','Þ','þ','ß','ÿ' };
	auto count = std::count_if(s.begin(), s.end(),
		[&vowel](char a)
		{
			auto result = std::find(vowel.begin(), vowel.end(), a);
			return (result == std::end(vowel)) ?  0 : 1;
		});
	timer.print();
	return count;
}

int32_t CountIfFor(const std::string& s)
{
	Timer timer("CountIf + for");
	std::vector<char> vowel{ 'À','à','Å','å','¨','¸','È','è','Î','î','Ó','ó','Û','û','Ý','ý','Þ','þ','ß','ÿ' };
	auto count = std::count_if(s.begin(), s.end(),
		[&vowel](char a)
		{
			size_t result = 0;
			for (char b : vowel)
			{
				if(a == b)
				{
					result++;
				}
			}
			return result;
		});
	timer.print();
	return count;
}

int32_t ForFind(const std::string& s)
{
	Timer timer("For + find");
	std::vector<char> vowel{ 'À','à','Å','å','¨','¸','È','è','Î','î','Ó','ó','Û','û','Ý','ý','Þ','þ','ß','ÿ' };
	size_t count = 0;
	for(char a : s)
		{
			auto result = std::find(vowel.begin(), vowel.end(), a);
			(result == std::end(vowel)) ? 0 : count++;
		};
	timer.print();
	return count;
}

int32_t ForFor(const std::string& s)
{
	Timer timer("For + for");
	std::vector<char> vowel{ 'À','à','Å','å','¨','¸','È','è','Î','î','Ó','ó','Û','û','Ý','ý','Þ','þ','ß','ÿ' };
	size_t count = 0;
	for (char a : s)
	{
		for (char b : vowel)
		{
			if (a == b)
			{ 
				count++;
			}
		}
	};
	timer.print();
	return count;
}

int main()
{
	std::ifstream file("War and peace.txt");
	file.seekg(0,std::ios::end);
	size_t size = file.tellg();
	file.seekg(0);
	std::string s(size, ' ');
	file.read(&s[0], size);

	std::cout << CountIfFind(s) << std::endl;
	std::cout << CountIfFor(s) << std::endl;
	std::cout << ForFind(s) << std::endl;
	std::cout << ForFor(s) << std::endl;

	return 0;
}