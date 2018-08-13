// 리스트의 ADT를 기반으로 정의된 main 함수
// 10_ListMain.c

#include<stdio.h>
#include "10_ArrayList.h"

int main(void)
{
	// ArrayList의 생성 및 초기화
	List list;
	int data;
	ListInit(&list);

	// 5개의 데이터 저장
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	// 저장된 데이터 전체 출력
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data)) // 첫 번째 데이터 조회
	{
		printf("%d ", data);

		while (LNext(&list, &data))	// 두 번째 이후의 데이터 조회
			printf("%d ", data);
	}
	printf("\n\n");

	// 숫자 22 제거
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// 삭제 후 남은 데이터 전체 출력
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}

	printf("\n\n");
	return 0;
}