#ifndef MINHEAP_H
#define MINHEAP_H

#define ONE 1
#define ZERO 0

#define TRUE 1
#define FALSE 0

typedef struct heap MinHeap;
typedef struct queue PriorityQueue;


PriorityQueue * minimum(MinHeap * minheap);
PriorityQueue  * removeMinimum(MinHeap * minheap);
PriorityQueue * create (char letter, int frequency);
void decreaseKey(MinHeap * minheap, int newFrequency, int position);
int getFrequency(PriorityQueue * queue);
char getLetter(PriorityQueue * queue);

void insertKey(char letter, int frequency, MinHeap * minheap);
void insertHeap (MinHeap * minheap, char letter, int frequency);
MinHeap * defineMinHeap(int capacity);
void minHeapify (MinHeap * minheap, int index);
void swap (PriorityQueue *x, PriorityQueue *y);
int smaller(int a, int b);
int underBounds(int value, int size);
int parent(int i);
int left(int i);
int right(int i);
int getCapacity(MinHeap * minheap);
int getHeapSize(MinHeap * minheap);

#endif
