#include <iostream>
#include <math.h>

char BoolCheck(bool x){
	if (x == true){
		std::cout << "True" << std::endl;
	}
	else{
		std::cout <<"False" << std::endl;
	}
}


int main(int argc, char** argv) {
	
	//---------Task1, написать порграмму, проверящую что сумма двух чисел лежит в пределах от 10 до 20 (включительно), если да - вывести true, в противном случае - false.
//int FirstVar = 0;
//int SecondVar = 0;
//int VarSum = 0;
//bool switcher = false;
//	
//std::cout << "Input first variable: " << std::endl;
//std::cin >> FirstVar;
//std::cout << "Input second variable: " << std::endl;
//std::cin >> SecondVar;
//
//VarSum = (FirstVar + SecondVar);
//	
//(VarSum >= 10 && VarSum <= 20) ? switcher = true : switcher = false;
//	
//BoolCheck(switcher);
	//-------------
	
	//----------Task2, написать программу, проверяющую, является ли некоторое число - натуральным простым.
int naturalis;
int Counter = 2;
int SqrtCounter;
bool NaturalPrime = false;

int NPChecker = 0;
		
	std::cout << "Input your number: " << std::endl;
	std::cin >> naturalis;
	SqrtCounter = sqrt(naturalis);

for (Counter; Counter <= SqrtCounter; (Counter++, NPChecker = 0))
{
	if((naturalis % Counter) != 0){
	//	Counter++;
	}
	else{
		NPChecker += 1;
		break;
	}
}

NPChecker == 0 ? NaturalPrime = true : NaturalPrime = false;
if(NaturalPrime == true){
	std::cout << naturalis << " is natural prime!" << std::endl;
}else{
	std::cout << naturalis << " is not natural prime!" << std::endl;
};
	//--------------------------------------------
	

	//----------Task3, Написать программу, выводящую на экран "истину", если две целочисленные константы, 
	//объявленные в ее начале либо равны десяти сами по себе, либо их сумма равна десяти.
//const int First = 4;
//const int Second = 6;
//
//bool ValuesEqualTen = false;
//if (First == 10 || Second == 10){
//	ValuesEqualTen = true;
//}
//
//bool SumOfNumbersEqualTen = false;
//if (First + Second == 10){
//	SumOfNumbersEqualTen = true;
//}
//
//if (ValuesEqualTen || SumOfNumbersEqualTen){
//	std::cout << "True" <<std::endl;
//}
//else{
//	std::cout << "False" <<std::endl;
//}
	//------------------------------------------------
	


	//------Task4-Написать программу, которая определяет является ли год високосным. Каждый 4й год является високосным, кроме каждого 100-го, при этом каждый 400-й - високосный.
	//--для проверки вывести результаты работы программы в консоль.
//int Year = 0;
//const int LowLeapChecker = 4;
//const int BigLeapChecker = 400;
//
//	std::cout << "Enter a year: ";
//	std::cin >> Year;
//	
//	bool LowerCheck = false;
//	bool BigCheck = false;
//	bool LeapCheck = false;
//	
//	if ((Year % LowLeapChecker) == 0){
//		LowerCheck = true;
//	};
//	
//	if (LowerCheck & Year >= 400){
//		((Year % BigLeapChecker) == 0) ? BigCheck = true : BigCheck = false;
//	};
//	
//	if(Year >= 400){
//		(LowerCheck & BigCheck) ? LeapCheck = true : LeapCheck = false;
//	}
//	else{
//		LowerCheck ? LeapCheck = true : LeapCheck = false;
//	};
//
//BoolCheck(LeapCheck);	
//	
	//---------------------------------------------------	
return 0;	
}
