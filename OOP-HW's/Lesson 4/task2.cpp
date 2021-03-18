#include <iostream>
#include <vector>
#include <cstdint>
#include <ctime>
#include <cstdlib>
#include <algorithm>


void PrintVector(std::vector<int32_t>& vec)
{
	for(uint32_t i = 0; i < vec.size(); i++)
	{	std::cout << vec[i] << " "; 	}
	std::cout << std::endl;
}
int32_t UnicNumbers(std::vector<int32_t>& Vec)
{
	int32_t Counter = 0;
	sort(Vec.begin(),Vec.end());
	PrintVector(Vec);
	for(uint32_t i = 0; i < Vec.size(); i++)
	{
		if(Vec[i] < Vec[i+1])
		{
			Counter++;
		}
	}
	return Counter;
}

int main()

{
	srand(time(NULL));
	std::vector<int32_t> Vector{};
	int32_t counter = 0;
	
	for (uint32_t i = 0; i < 25; i++)
	{
		Vector.push_back(1 + rand() % 100);
	}
	PrintVector(Vector);
	std::cout << std::endl;
	std::cout << UnicNumbers(Vector);
	
	
	
	
	return 0;
}
