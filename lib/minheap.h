#ifndef MINHEAP_H
#define MINHEAP_H
#include "../lib/priorityqueue.h"

#define ONE 1
#define TRUE 1
#define FALSE 0

typedef struct heap MinHeap;

MinHeap * defineMinHeap(int capacity);
void minHeapify (MinHeap * minheap, int index);
void buildMinHeap (MinHeap * minheap, int elementsQuantity);
void swap (PriorityQueue **x, PriorityQueue **y);
int smaller(int a, int b);
int underBounds(int value, int size);
int parent(int i);
int left(int i);
int right(int i);
int getCapacity(MinHeap * minheap);
int getHeapSize(MinHeap * minheap);
PriorityQueue * getArrayIn(MinHeap * minheap, int index);
void setHeapSize(MinHeap * minheap, int heapsize);
void setArray(MinHeap * minheap, PriorityQueue * new, int index);

#endif
