#ifndef MINHEAP_H
#define MINHEAP_H

#define ONE 1
#define ZERO 0
#define MAX_SIZE 1000
#define TRUE 1
#define FALSE 0

typedef struct heap MinHeap;
typedef struct queue PriorityQueue;

PriorityQueue * minimum(MinHeap * minheap);
PriorityQueue  * removeMinimum(MinHeap * minheap);
PriorityQueue * create (int letter, int frequency);
PriorityQueue * createDad (PriorityQueue * left, PriorityQueue * right);
void decreaseKey(MinHeap * minheap, int newFrequency, int position);
int getFrequency(PriorityQueue * queue);
int getLetter(PriorityQueue * queue);

void insertKey(char letter, int frequency, MinHeap * minheap);
void insertHeap (MinHeap * minheap, int letter, int frequency);
void insertDadHeap(MinHeap * minheap, PriorityQueue * pq);
MinHeap * defineMinHeap();
void minHeapify (MinHeap * minheap, int index);
void swap (PriorityQueue *x, PriorityQueue *y);
int underBounds(int value, int size);
int parent(int i);
int left(int i);
int right(int i);
int getCapacity(MinHeap * minheap);
int getHeapSize(MinHeap * minheap);

#endif
