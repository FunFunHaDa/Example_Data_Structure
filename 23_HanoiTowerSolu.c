#include<stdio.h>

void HanoiTwoerMove(int num, char from, char by, char to)
{
	if (num == 1)
		printf("����1�� %c���� %c�� �̵� \n", from, to);
	else
	{
		HanoiTwoerMove(num - 1, from, to, by);
		printf("����%d��(��) %c���� %c�� �̵� \n", num, from, to);
		HanoiTwoerMove(num - 1, by, from, to);
	}
}

int main(void)
{
	HanoiTwoerMove(3, 'A', 'B', 'C');
	return 0;
}