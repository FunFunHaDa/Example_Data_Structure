#include<stdio.h>
#include "29_SimpleHeap.h"

int main(void)
{
	Heap heap;
	HeapInit(&heap);	// ÈüÀÇ ÃÊ±âÈ­

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));

	while (!HisEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0; 
}