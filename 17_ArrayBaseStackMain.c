#include<stdio.h>
#include "17_ArrayBaseStack.h"

int main(void)
{
	// Stack의 생성 및 초기화
	Stack stack;
	StackInit(&stack);

	// 데이터 넣기
	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	// 데이터 출력
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}