#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "../lib/minheap.h"

typedef struct queue PriorityQueue; 

PriorityQueue * definePriorityQueue (int capacity);
void insertKey(char letter, int frequency, MinHeap * minheap);
int getFrequency (PriorityQueue * queue);
char getLetter (PriorityQueue * queue);


#endif
