#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../lib/minheap.h"

typedef struct heap{
	PriorityQueue *array;
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
	minimumHeap->array = (PriorityQueue *)malloc(sizeof(PriorityQueue)*MAX_SIZE);
	int i;
	for(i=0;i<MAX_SIZE;i++){
		minimumHeap->array[i].letter=-1;
		minimumHeap->array[i].frequency=-1;
		minimumHeap->array[i].left = NULL;
		minimumHeap->array[i].right = NULL;
	}
	minimumHeap->heapsize = 0;
	minimumHeap->capacity = MAX_SIZE;
	return minimumHeap;
}

void minHeapify_up(MinHeap * minheap, int index){
	if (index == ZERO)
		return;
	int indexParent = parent(index);
	int indexFrequency = getFrequency(&minheap->array[index]);
	int parentFrquency = getFrequency(&minheap->array[indexParent]);
	if (indexFrequency < parentFrquency){
		printf("%d-----%d \n", minheap->array[index].letter, minheap->array[indexParent].letter);
		swap(&minheap->array[index],&minheap->array[indexParent]);
		printf("%d--*--%d \n", minheap->array[index].letter, minheap->array[indexParent].letter);
		minHeapify_up(minheap, indexParent);
	}
}

void minHeapify_down(MinHeap * minheap, int index){
	int minimum = index;

	if (underBounds(left(index), minheap->heapsize) && getFrequency(&minheap->array[left(index)]) < getFrequency(&minheap->array[minimum]))
		minimum = left(index);

	if (underBounds(right(index), minheap->heapsize) && getFrequency(&minheap->array[right(index)]) < getFrequency(&minheap->array[minimum]))
		minimum = right(index);

	if (minimum != index){
		swap(&minheap->array[index],&minheap->array[minimum]);
		minHeapify_down(minheap, minimum);
	}
}

void removeHeap(MinHeap * minheap, int position){
	printf("%d-----%d \n", minheap->array[position].letter, minheap->array[minheap->heapsize - ONE].letter);
	swap(&minheap->array[position], &minheap->array[minheap->heapsize - ONE]);
	printf("%d-----%d \n", minheap->array[position].letter, minheap->array[minheap->heapsize - ONE].letter);
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
	PriorityQueue tmp = *x;
	*x = *y;
	*y = tmp;
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

void imprimirheap(PriorityQueue array[], int a){
	int i;
	for(i=0;i<a;i++){
		printf("%d ", array[i].letter);
	}
}
void insertHeap (MinHeap * minheap, int letter, int frequency){
	int index = minheap->heapsize;
	if (index == minheap->capacity)
		return;
	//minheap->array[index] = create(letter, frequency);
	minheap->array[index].letter=letter;
	minheap->array[index].frequency=frequency;
	minheap->array[index].left=NULL;
	minheap->array[index].right=NULL;
	imprimirheap(minheap->array, minheap->heapsize);
	minHeapify_up(minheap, index);
	minheap->heapsize = ++index;
	printf("\n\nHEAP SIZE ====== %d\n\n", minheap->heapsize);
}

void insertDadHeap(MinHeap * minheap, PriorityQueue * pq){
	int i = minheap->heapsize;
	if (i == minheap->capacity)
		return;
	//minheap->array[i].letter = pq->letter;
	//minheap->array[i].frequency = pq->frequency;
	//minheap->array[i].left=pq->left;
	//minheap->array[i].right=pq->right;
	minheap->array[i] = *pq;
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
	return &minheap->array[index];
}

PriorityQueue * minimum(MinHeap * minheap){
    if (minheap)
	   return getArrayIn(minheap, ZERO);
    return NULL;
}

PriorityQueue  * removeMinimum(MinHeap * minheap){
	PriorityQueue * minimal = minimum(minheap);
	imprimirheap(minheap->array, minheap->heapsize);
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
	return 0;
}

int getLetter(PriorityQueue * queue){
	if (queue)
		return queue->letter;
	return 0;
}
