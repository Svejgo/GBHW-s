#include <iostream>


void ArrayPrint(int* array, int ArrSize)
{
	int counter;
	for (counter = 0; counter < ArrSize; counter++)
	{
		std::cout << array[counter] << " ";
	}
	std::cout << std::endl;
	
}

void ArrayCycle(int* array, int ArrSize, int mover)
{
	int counter;
	int temp = array[ArrSize - mover];
    std::cout << std::endl << temp << std::endl; //дебаг темпа
	
	for(counter = 0; counter < ArrSize; counter+=mover)
	{
		temp = temp ^ array[counter];
		array[counter] = temp ^ array[counter];
		temp = temp ^ array[counter];
		
	}
	
	//1 2 3 4 5 
	//5 1 2 3 4 
}
//сделать цикличное смещение массива на заданный шаг (при отриц. значении смещать в обратную сторону)

int main(int argc, char** argv) {
	
	
	int Array[5] = {1, 2, 3, 4 ,5};
	int ArrSize = sizeof(Array) / sizeof(Array[0]);
	
	ArrayPrint(Array, ArrSize);
	
	int mover = 2;
	
	ArrayCycle(Array, ArrSize, mover);
	
	ArrayPrint(Array, ArrSize);
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
