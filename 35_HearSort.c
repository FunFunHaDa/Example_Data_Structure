#include<stdio.h>
#include "30_UsefulHeap.h"

int PriComp(int n1, int n2)
{
	return n2 - n1;
}

void Heapsort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	int i;
	HeapInit(&heap, pc);

	// ���Ĵ���� ������ ���� ����
	for (i = 0; i < n; i++)
		HInsert(&heap, arr[i]);

	// ������� �ϳ��� ������ ����
	for (i = 0; i < n; i++)
		arr[i] = HDelete(&heap);
}

	int main(void)
	{
		int arr[4] = { 3, 4, 1, 2 };
		int i;

		Heapsort(arr, sizeof(arr) / sizeof(int), PriComp);

		for (i = 0; i < 4; i++)
			printf("%d ", arr[i]);

		printf("\n");
		return 0;
	}
