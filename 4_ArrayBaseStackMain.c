#include<stdio.h>
#include"4_ArrayBaseStack.h"

int main(void)
{
	Stack stack;
	StackInit(&stack);

	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	while (!SisEmpty(&stack))
		printf("%d ", SPop(&stack));
}