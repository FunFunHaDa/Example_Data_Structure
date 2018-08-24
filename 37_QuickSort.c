#include<stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽
	int low = left + 1;
	int high = right;

	while (low <= high)	// 교차되지 않을 때까지 반복
	{
		// 피벗보다 큰 값을 찾음
		while (pivot > arr[low])
			low++;	// low를 왼쪽으로 이동

		// 피벗보다 작은 값을 찾음
		while (pivot < arr[high])
			high--;	// high를 왼쪽으로 이동

		// 교차되지 않은 상태면 Swap실행
		if (low <= high)
			Swap(arr, low, high);
	}

	Swap(arr, left, high);	// 피벗과 high가 가리키는 대상 교환
	return high;			// 옮겨진 피벗의 위치정보 반환
}

void QuicSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right); // 둘로 나눔
		QuicSort(arr, left, pivot - 1);	// 왼쪽 영역 정렬
		QuicSort(arr, pivot + 1, right);// 오른쪽 영역 정렬
	}
}

int main(void)
{
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuicSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}