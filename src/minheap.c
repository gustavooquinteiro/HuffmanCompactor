#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../lib/minheap.h"

typedef struct heap{
	PriorityQueue *array[MAX_SIZE];
	int capacity;
	int heapsize;
} MinHeap;

typedef struct queue{
	int letter;
	int frequency;
	PriorityQueue * left; 
	PriorityQueue * right;
} PriorityQueue;

MinHeap * defineMinHeap(){
	MinHeap * minimumHeap = (MinHeap *)malloc(sizeof(MinHeap));
	minimumHeap->heapsize = 0;
	minimumHeap->capacity = MAX_SIZE;
	return minimumHeap;
}

void minHeapify_up(MinHeap * minheap, int index){
	if (index == ZERO)
		return;
	int indexParent = parent(index);
	int indexFrequency = getFrequency(minheap->array[index]);
	int parentFrquency = getFrequency(minheap->array[indexParent]);
	if (indexFrequency < parentFrquency){
		swap(minheap->array[index], minheap->array[indexParent]);
		minHeapify_up(minheap, indexParent);
	}
}

void minHeapify_down(MinHeap * minheap, int index){
	int minimum = index;

	if (underBounds(left(index), minheap->heapsize) && getFrequency(minheap->array[left(index)]) < getFrequency(minheap->array[minimum])) 
		minimum = left(index);

	if (underBounds(right(index), minheap->heapsize) && getFrequency(minheap->array[right(index)]) < getFrequency(minheap->array[minimum]))
		minimum = right(index);

	if (minimum != index){
		swap(minheap->array[index], minheap->array[minimum]);
		minHeapify_down(minheap, minimum);
	}
}

void removeHeap(MinHeap * minheap, int position){
	swap(minheap->array[position], minheap->array[minheap->heapsize - ONE]);
	//free(minheap->array[minheap->heapsize - ONE]);
	//minheap->array[minheap->heapsize - ONE ] = NULL;
	minheap->heapsize--;
	minHeapify_down(minheap, position);
}

void deleteHeap(MinHeap * minheap){
	free(minheap);
	minheap = NULL;
}

void swap(PriorityQueue *x, PriorityQueue *y){
	printf("*** SWAP ***");
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
	int index = minheap->heapsize;
	if (index == minheap->capacity)
		return;
	minheap->array[index] = create(letter, frequency);
	minHeapify_up(minheap, index);
	minheap->heapsize = ++index;
	printf("\n\nHEAP SIZE ====== %d\n\n", minheap->heapsize);
}

void insertDadHeap(MinHeap * minheap, PriorityQueue * pq){
	int i = minheap->heapsize;
	if (i == minheap->capacity)
		return;
	/*minheap->array[i]->letter = pq->letter;
	minheap->array[i]->frequency = pq->frequency;
	minheap->array[i]->left=pq->left;
	minheap->array[i]->right=pq->right;*/
	minheap->array[i] = pq; 
	printf("\n DAD FREQUENCY === %d\n", pq->frequency);
	i++;
	minheap->heapsize = i;
	minHeapify_up(minheap, minheap->heapsize);
}

int underBounds(int value, int size){
	return (value <= size)? TRUE: FALSE;
}

int parent(int i){
	printf("\n--INDEX == %d    INDEX DO PAI DELE ==%d--\n", i, (int)floor((i - ONE) >> ONE));
	return (int)floor((i - ONE) >> ONE);
}

int left(int i){
	return (i << ONE); 
}

int right(int i){
	return (i << ONE | ONE);
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
	if (minimal){
		removeHeap(minheap, ZERO);
		return minimal;
	}
	return NULL;
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
	new->frequency = getFrequency(left) + getFrequency(right);
	new->left = left;
	new->right = right;
	return new;
}

int getFrequency(PriorityQueue * queue){
	if(queue)
		return queue->frequency;
	return 0;
}

int getLetter(PriorityQueue * queue){
	if (queue)
		return queue->letter;
	return 0;
}
