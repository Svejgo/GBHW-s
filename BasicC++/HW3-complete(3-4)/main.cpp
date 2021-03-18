#include <iostream>
#include "task3.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

//-----------------Task#1
const int a = 1;
const int b = 2;
const int c = 3;
const int d = 4;

std::cout << (a * (b + ( static_cast<float>(c) / d ))) <<std::endl;
//------------------------


//-----------------Task#2	
	float Task2Number;
	
	std::cout << "input your number: " << std::endl;
	std::cin >> Task2Number;
	(Task2Number > 21) ? std::cout << (Task2Number - 21) * 2 : std::cout << (21 - Task2Number);
	std::cout << std::endl;
//------------------------	

//-----------------Task#3
extern int varA;
extern int varB;
extern int varC;
extern int varD;

std::cout << (varA * (varB + ( static_cast<float>(varC) / varD )));
//------------------------



//-----------------Task#4
//int Array[3][3][3] = {
//{{1,2,3},{2,1,3},{3,2,3}},
//{{5,1,9},{4,7,6},{2,2,1}},
//{{1,5,8},{4,3,7},{4,1,7}}
//};
// int* Pointer[1][1][1] = Array;	//вот тут возникла ошибка [Error] array must be initialized with a brace-enclosed initializer; не смог пока победить :(
//------------------------

	
	return 0;
}
