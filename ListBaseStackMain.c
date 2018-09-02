#include<stdio.h>	// p 217, 연결 리스트 기반 스택
#include "ListBaseStack.h"

int main(void)
{
	Stack stack;
	StackInit(&stack);

	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));
	
	return 0;
}