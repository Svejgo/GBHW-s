#include <iostream>



void ArrPrint(int* ArrayToPrint, int ArrSize)
{
	int PrintCounter;
	for(PrintCounter = 0; PrintCounter < ArrSize; PrintCounter++)
	{
	 std::cout << ArrayToPrint[PrintCounter] << " ";
	}
	std::cout << std::endl;
}

//task1
void ArrSwap(int* ArrayToSwap, int ArrSize)
{
	int s;
	for(s = 0; s < ArrSize; s++)
	{
	 ArrayToSwap[s] == 0 ? ArrayToSwap[s] = 1 : ArrayToSwap[s] = 0;
	}
	
}

//task2
void ArrFill(int* ArrayToFill, int ArrSize)
{
	int FillCounter;
	int Filler = 1;
	for (FillCounter = 0; FillCounter < ArrSize; FillCounter++)
	{
		ArrayToFill[FillCounter] += Filler;
		Filler += 3;
	}
}

//task3
int ElementsSum(int* ArrayToSum, int ArrStart, int ArrEnd)
{
	int sum = 0;
	int Counter = 0;
	for (int Counter = ArrStart; Counter <= ArrEnd; Counter++)
	{
		sum += ArrayToSum[Counter];
	}
	return sum;
}

bool HalfComparsion(int* ArrayToCheck, int ArrSize)
{
	int Counter;
	for (Counter = 0; Counter < ArrSize; Counter++)
	{
		if (ElementsSum(ArrayToCheck, 0, Counter) == ElementsSum(ArrayToCheck, Counter+1, ArrSize-1))
			return true;
		
	}
	return false;
}
