#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

void HeapPrint(Heap* php);
void HeapInit(Heap* php);
void HeapDestroy(Heap* php);

void Swap(HPDataType* p1, HPDataType* p2);
void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int size, int parent);

void HeapPush(Heap* php, HPDataType x);
void HeapPop(Heap* php);

HPDataType HeapTop(Heap* php);
bool isHeapEmpty(Heap* php);
int HeapSize(Heap* php);
