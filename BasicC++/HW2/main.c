//HW2, �������� �������, dev-c++ 5.11
#include <stdio.h>
#include <stdlib.h>



int main() {
printf("Please, enter a count of triangle's lines: ");
	int count;
	scanf("%d", &count);
	if (count <= 0) {
		printf("Can't draw triangle without lines. ");
		return;
	}

	if (count == 1) {
		printf("^"); // ��, ���� ���� �����������...
		return;
	}

	int countOfSymbolsInLine = count * 2 - 1; // ������� ����� ������� ��� ���������� ����������������
	int center = (countOfSymbolsInLine / 2);
	for (int symbol = 0; symbol < countOfSymbolsInLine; symbol++) {
		if (symbol == center) {
			printf("^");
			break;
		}
		printf(" ");
	}
	printf("\n");
	for (int line = 1; line < count - 1; line++) {
		for (int symbol = 0; symbol < countOfSymbolsInLine; symbol++) {
			if (symbol == (center - line)) {
				printf("^");
				continue; // ���� ������ ������� ������������
			}

			if (symbol == (center + line)) {
				printf("^");
				break; // ��, ������ ������ ������, ����� ���������
			}

			printf(" ");
		}
		printf("\n");
	}
	for (int symbol = 0; symbol < countOfSymbolsInLine; symbol++) {
		printf("^");
	}
	printf("\n");
	return 0;
}
