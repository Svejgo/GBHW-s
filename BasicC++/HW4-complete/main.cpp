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
	
	//---------Task1, �������� ���������, ���������� ��� ����� ���� ����� ����� � �������� �� 10 �� 20 (������������), ���� �� - ������� true, � ��������� ������ - false.
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
	
	//----------Task2, �������� ���������, �����������, �������� �� ��������� ����� - ����������� �������.
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
	

	//----------Task3, �������� ���������, ��������� �� ����� "������", ���� ��� ������������� ���������, 
	//����������� � �� ������ ���� ����� ������ ���� �� ����, ���� �� ����� ����� ������.
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
	


	//------Task4-�������� ���������, ������� ���������� �������� �� ��� ����������. ������ 4� ��� �������� ����������, ����� ������� 100-��, ��� ���� ������ 400-� - ����������.
	//--��� �������� ������� ���������� ������ ��������� � �������.
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
