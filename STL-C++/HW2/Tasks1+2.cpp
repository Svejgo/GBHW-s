#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

template  <typename T>
void Swap(T* lhs, T* rhs)
{
	T ptemp = *lhs;
	*lhs = *rhs;
	*rhs = ptemp;	
}

template <typename T>
void SortPointers(std::vector<T*>& vec)
{
	std::sort(vec.begin(), vec.end(), [](T* a, T* b) { return *a < *b; });
}

template <typename T>
void print(std::vector<T*>& vec)
{
	for (auto i : vec)
	{
		std::cout << *i << ' ' << std::endl;
	}
	std::cout << std::endl;
}
//
//int main()
//{
//	int32_t a = 5;
//	int32_t b = 10;
//	int32_t c = 7;
//	int32_t d = 2;
//
//	int32_t* pa = &a;
//	int32_t* pb = &b;
//	int32_t* pc = &c;
//	int32_t* pd = &d;
//
//	std::vector <int32_t*> vec{pa,pb,pc,pd};
//
//	print(vec);
//	SortPointers(vec);
//	print(vec);
//
//	std::cout << "Before swap: " << std::endl;
//	std::cout << "value: " << *pa << ' ' << *pb << std::endl;
//	std::cout << "adresses: " << pa << ' ' << pb << std::endl;
//
//	std::cout << "After swap: " << std::endl;
//	Swap(pa, pb);
//
//	std::cout << "value: " << *pa << ' ' << *pb << std::endl;
//	std::cout << "adresses: " << pa << ' ' << pb << std::endl;
//
//	return 1;
//}