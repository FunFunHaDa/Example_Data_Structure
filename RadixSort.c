#include<stdio.h>	// p 418, 기수 정렬
#include "ListBaseQueue.h"

#define BUCKET_NUM 10

void RadixSort(int arr[], int num, int maxLen)
{
	Queue buckets[BUCKET_NUM];
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	// 10개의 초기화
	for (bi = 0; bi < BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	// 가장 긴 데이터의 길이만큼 반복
	for (pos = 0; pos < maxLen; pos++)
	{
		// 정렬대상의 수만큼 반복
		for (di = 0; di < num; di++)
		{
			radix = (arr[di] / divfac) % 10;	// N번째 자리의 숫자 추출
			Enqueue(&buckets[radix], arr[di]);	// 버킷에 데이터 저장
		}

		for (bi = 0, di = 0; bi < BUCKET_NUM; bi++)
		{
			while (!QIsEmpty(&buckets[bi]))
				arr[di++] = Dequeue(&buckets[bi]);
		}
		divfac *= 10;	// 피제수의 증가
	}
}

int main(void)
{
	int arr[7] = { 13, 212, 14, 7141, 10987, 6, 15 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	RadixSort(arr, len, 5);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}