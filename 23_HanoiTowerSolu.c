#include<stdio.h>

void HanoiTwoerMove(int num, char from, char by, char to)
{
	if (num == 1)
		printf("원반1을 %c에서 %c로 이동 \n", from, to);
	else
	{
		HanoiTwoerMove(num - 1, from, to, by);
		printf("원반%d을(를) %c에서 %c로 이동 \n", num, from, to);
		HanoiTwoerMove(num - 1, by, from, to);
	}
}

int main(void)
{
	HanoiTwoerMove(3, 'A', 'B', 'C');
	return 0;
}