#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEPA_LEN 100

typedef char HData;
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp * comp;
	int numOfData;
	HData HeapArr[HEPA_LEN];
}Heap;

void HeapInit(Heap * ph, PriorityComp pc);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);


#endif // !__USEFUL_HEAP_H__
