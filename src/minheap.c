#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../lib/minheap.h"

typedef struct heap{
	PriorityQueue **array;
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
	minimumHeap->heapsize = ZERO;
	minimumHeap->capacity = capacity;
	minimumHeap->array = (PriorityQueue **)malloc(minimumHeap->capacity *  sizeof(PriorityQueue*));
	return minimumHeap;
}

void minHeapify_up(MinHeap * minheap, int index){

	if (index == ZERO) return;
	int indexParent = parent(index);
	int indexFrequency = getFrequency(minheap->array[index]);
	int parentFrquency = getFrequency(minheap->array[indexParent]);

	if (indexFrequency < parentFrquency){
	//	printf("%d-----%d \n", minheap->array[index]->letter, minheap->array[indexParent]->letter);
		swap(&minheap->array[indexParent], &minheap->array[index]);
	//	printf("%d--*--%d \n", minheap->array[index]->letter, minheap->array[indexParent]->letter);
		minHeapify_up(minheap, indexParent);
	}
}

void minHeapify_down(MinHeap * minheap, int index){
	int minimum = index;
	// printf("LEFT == %d\n", left(index));
	// printf("RIGHT == %d\n", right(index));
	int leftFrequency = getFrequency(minheap->array[left(index)]); 
	int rightFrequency = getFrequency(minheap->array[right(index)]); 
	int atualFrequency = getFrequency(minheap->array[index]);
	
	if (underBounds(left(index), minheap->heapsize) && leftFrequency < atualFrequency){
		minimum = left(index);
		atualFrequency = getFrequency(minheap->array[minimum]);
	}
	
	if (underBounds(right(index), minheap->heapsize) && rightFrequency < atualFrequency)
		minimum = right(index);

	if (minimum != index){
		swap(&minheap->array[minimum], &minheap->array[index]);
		minHeapify_down(minheap, minimum);
	}
}

void removeHeap(MinHeap * minheap, int position){
	// printf("POSIITON ==%d\n", position);
	//printf("%d-----%d \n", minheap->array[position]->letter, minheap->array[minheap->heapsize - ONE]->letter);
	swap(&minheap->array[position], &minheap->array[minheap->heapsize - ONE]);
	//printf("%d-----%d \n", minheap->array[position]->letter, minheap->array[minheap->heapsize - ONE]->letter);
	// free(minheap->array[minheap->heapsize - ONE]);
	// minheap->array[minheap->heapsize - ONE ] = NULL;
	--minheap->heapsize;
	minHeapify_down(minheap, position);
}

void deleteHeap(MinHeap * minheap){
	free(minheap);
	minheap = NULL;
}

void swap(PriorityQueue **x, PriorityQueue **y){
	PriorityQueue * tmp = *x;
	*x = *y;
	*y = tmp;
}

void imprimirheap(PriorityQueue ** array, int a){
	printf("\n\n\n VAI IMPRIMIR O CARALHO DO HEAP \n\n\n");
	int i;
	for(i=0;i<a;i++){
		printf("LETRA = %d COM FREQUENCIA = %d \n", array[i]->letter, array[i]->frequency);
	}
}
void insertHeap (MinHeap * minheap, int letter, int frequency){
	int index = minheap->heapsize;

	
	if (index == minheap->capacity) return;
	
	minheap->array[index] = create(letter, frequency);
	minHeapify_up(minheap, index);
	minheap->heapsize = ++index;
	imprimirheap(minheap->array, minheap->heapsize);
}

void insertDadHeap(MinHeap * minheap, PriorityQueue * pq){
	int i = minheap->heapsize;
	if (i == minheap->capacity)	return;

	/*minheap->array[i]->letter = pq->letter;
	minheap->array[i]->frequency = pq->frequency;
	minheap->array[i]->left=pq->left;
	minheap->array[i]->right=pq->right;*/
	minheap->array[i] = pq; 
	printf("\n DAD FREQUENCY === %d\n", pq->frequency);

	i++;
	minheap->heapsize = i;
	minHeapify_up(minheap, minheap->heapsize);
	imprimirheap(minheap->array, minheap->heapsize);
}

int underBounds(int value, int size){
	return (value < size);
}

int parent(int i){
	return (int)floor((i - ONE) >> ONE);
}

int left(int i){
	return (i << ONE | ONE);
}

int right(int i){
	return ((i << ONE) + (ONE << ONE ));
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
	//imprimirheap(minheap->array, minheap->heapsize);
	if (minimal){
		removeHeap(minheap, ZERO);
		imprimirheap(minheap->array, minheap->heapsize);
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
	return ZERO;
}

int getLetter(PriorityQueue * queue){
	if (queue)
		return queue->letter;
	return ZERO;
}
