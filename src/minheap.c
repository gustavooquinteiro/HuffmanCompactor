#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../lib/minheap.h"

typedef struct heap{
	PriorityQueue ** array;
	int capacity;
	int heapsize;
} MinHeap;

typedef struct queue{
	int letter;
	int frequency;
	PriorityQueue * left;
	PriorityQueue * right;
} PriorityQueue;

MinHeap * defineMinHeap(int capacity){
	MinHeap * minimumHeap = (MinHeap *)malloc(sizeof(MinHeap));
	minimumHeap->array = (PriorityQueue **)malloc(sizeof(PriorityQueue*)*500);
	int i;
	for(i=0;i<500;i++){
	minimumHeap->array[i] = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	}
	minimumHeap->heapsize = 0;
	minimumHeap->capacity = capacity;
	return minimumHeap;
}

void minHeapify_up(MinHeap * minheap, int index){
	if (index == ZERO)
		return;
	int indexParent = parent(index);
	printf("\n--%d %d--\n", index, indexParent);
	if (getFrequency(minheap->array[index]) < getFrequency(minheap->array[indexParent])){
		swap(minheap->array[index], minheap->array[indexParent]);
		minHeapify_up(minheap, indexParent);
	}
}

void minHeapify_down(MinHeap * minheap, int index){
	int minimum = index;

	if (underBounds(left(index), minheap->heapsize))
		minimum = smaller(getFrequency(minheap->array[minimum]),getFrequency(minheap->array[left(index)]));

	if (underBounds(right(index), minheap->heapsize))
		minimum = smaller(getFrequency(minheap->array[minimum]), getFrequency(minheap->array[right(index)]));

	if (minimum != index){
		swap(minheap->array[index], minheap->array[minimum]);
		minHeapify_down(minheap, minimum);
	}
}

void removeHeap(MinHeap * minheap, int position){
	swap(minheap->array[position], minheap->array[minheap->heapsize]);
	free(minheap->array[minheap->heapsize]);
	minheap->array[minheap->heapsize] = NULL;
	minheap->heapsize--;
	minHeapify_down(minheap, position);
}

void deleteHeap(MinHeap * minheap){
	free(minheap);
	minheap = NULL;
}

void swap(PriorityQueue *x, PriorityQueue *y){
	printf("*****");
	PriorityQueue * tmp = x;
	x = y;
	y = tmp;
	/*PriorityQueue * tmp = (PriorityQueue*) malloc(sizeof(PriorityQueue));
	tmp->letter = x->letter;
	tmp->frequency = x->frequency;
	tmp->left=x->left;
	tmp->right=x->right;

	x->letter=y->letter;
	x->frequency=y->frequency;
	x->left=y->left;
	x->right=y->right;

	y->letter=tmp->letter;
	y->frequency=tmp->frequency;
	y->left=tmp->left;
	y->right=tmp->right;*/

}

void insertHeap (MinHeap * minheap, int letter, int frequency){
	int i = minheap->heapsize;
	if (i == minheap->capacity)
		return;
	minheap->array[i] = create(letter, frequency);
	i++;
	minheap->heapsize = i;
	printf("\n\n%d\n\n", minheap->heapsize);
	minHeapify_up(minheap, minheap->heapsize);
}

void insertDadHeap(MinHeap * minheap, PriorityQueue * pq){
	int i = minheap->heapsize;
	if (i == minheap->capacity)
		return;
	minheap->array[i]->letter = pq->letter;
	minheap->array[i]->frequency = pq->frequency;
	minheap->array[i]->left=pq->left;
	minheap->array[i]->right=pq->right;
	printf("\n(%d)\n", pq->frequency);
	i++;
	minheap->heapsize = i;
	minHeapify_up(minheap, minheap->heapsize);
}

int smaller (int a, int b){
	return a < b? a: b;
}

int underBounds(int value, int size){
	return (value <= size)? TRUE: FALSE;
}

int parent(int i){
	return (i - ONE) << ONE;
}

int left(int i){
	return i >> ONE | ONE;
}

int right(int i){
	return i >> ONE ;
}

int getCapacity(MinHeap * minheap){
	return minheap->capacity;
}

int getHeapSize(MinHeap * minheap){
	return minheap->heapsize;
}

PriorityQueue * getArrayIn(MinHeap * minheap, int index){
	return minheap->array[index];
}

PriorityQueue * minimum(MinHeap * minheap){
    if (minheap)
	   return getArrayIn(minheap, ZERO);
    return NULL;
}

PriorityQueue  * removeMinimum(MinHeap * minheap){
	PriorityQueue * minimal = minimum(minheap);
	removeHeap(minheap, ZERO);
	return minimal;
}

void decreaseKey(MinHeap * minheap, int newFrequency, int position){
	PriorityQueue * updated = getArrayIn(minheap, position);
	updated->frequency = newFrequency;
	minHeapify_up(minheap, position);
}

PriorityQueue * create (int letter, int frequency){
	PriorityQueue * new = (PriorityQueue *)malloc(sizeof(PriorityQueue));
	new->letter = letter;
	new->frequency = frequency;
	new->left = NULL;
	new->right = NULL;
	return new;
}

PriorityQueue * createDad (PriorityQueue * left, PriorityQueue * right){
	PriorityQueue * new = (PriorityQueue *)malloc(sizeof(PriorityQueue));
	new->letter = 128;
	new->frequency = left->frequency + right->frequency;
	new->left = left;
	new->right = right;
	return new;
}

int getFrequency(PriorityQueue * queue){
	if(queue->frequency)
		return queue->frequency;
	else
		return 0;
}

int getLetter(PriorityQueue * queue){
	return queue->letter;
}
