#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void ArrSwap(int* ArrayToSwap, int ArrSize);
void ArrPrint(int* ArrayToPrint, int ArrSize);
void ArrFill(int* ArrayToFill, int ArrSize);
bool HalfComparsion(int* ArrayToCheck, int ArrSize);

int main(int argc, char** argv) {
	
{//task1--------------------------
std::cout << "Task 1" << std::endl;
int Task1Array[8] = { 1, 0, 1, 0, 0, 1, 0, 1 };
int ArrSize = sizeof(Task1Array) / sizeof(Task1Array[0]);

ArrPrint(Task1Array, ArrSize);
ArrSwap(Task1Array, ArrSize);
ArrPrint(Task1Array, ArrSize);

}//task1--------------------------

{//task2--задать пустой целочисленный массив размером 8. Ќаписать функцию, котора€ с помощью цикла заполнит его значени€ми 1 4 7 10 13 16 19 22.
std::cout << "Task 2" << std::endl;
int Task2Array[8] = {};
int ArrSize = sizeof(Task2Array) / sizeof(Task2Array[0]);

ArrFill(Task2Array, ArrSize);
ArrPrint(Task2Array, ArrSize);

}//task2--------------------------

{//task3--написать метод, в который передаетс€ не пустой одномерный целочисленный массив, метод должен вернуть истину, если в массиве есть место, в котором сумма левой и правой частей 
//--массива равны.
std::cout << "Task 3" << std::endl;

int Task3Array[6] = {1, 3, 5, 5, 3, 1};
int ArrSize = sizeof(Task3Array) / sizeof(Task3Array[0]);
ArrPrint(Task3Array, ArrSize);
std::cout <<(HalfComparsion(Task3Array,ArrSize) ? "True" : "False");


}//task3

//--task4 - написать функцию, которой на вход подаетс€ одномерный массив, а также число n (может быть как положительным, так и отрицательным.
//--ѕри этом метод должен циклически сместить все элементы массива на n позиций.
//к сожалению € не успел нормально засесть за этот таск, но если можно - не оставл€йте пж подсказок по нему, € постараюсь его сделать сам и потом проконсультируюсь с вами
//(€ не смотрю разборы домашек на запис€х лекций, пока сам домашку не сдам :) )

//--task4



return 0;
}
