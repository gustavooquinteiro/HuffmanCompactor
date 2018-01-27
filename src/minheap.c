/*
 * minheap.c
 * 
 * Copyright 2018 Gustavo Oliveira Quinteiro <gustavo200976@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include " ../lib/minheap.h"

typedef struct heap{
	PriorityQueue ** array;
	int capacity;
	int heapsize;
} MinHeap;

MinHeap * defineMinHeap(int capacity){
	MinHeap * minimumHeap = (MinHeap *)malloc(sizeof(MinHeap)); 
	minimumHeap->heapsize = 0;
	minimumHeap->capacity = capacity;
	*(minimumHeap->array) = definePriorityQueue(capacity);
	return minimumHeap;
}

void minHeapify(MinHeap * minheap, int index){
	int minimum = index;
	
	if (underBounds(left(index), minheap->heapsize))
		minimum = smaller(getFrequency(minheap->array[minimum]), getFrequency(minheap->array[left(index)])); 
		
	if (underBounds(right(index), minheap->heapsize))
		minimum = smaller(getFrequency(minheap->array[minimum]), getFrequency(minheap->array[right(index)]));
		
	if (minimum != index){
		swap(&minheap->array[index], &minheap->array[minimum]); 
		minHeapify(minheap, minimum); 
	}
}

void buildMinHeap(MinHeap * minheap, int elementsQuantity){
	register int iterator; 
	for(iterator = ceil(parent(elementsQuantity)); iterator > ONE; iterator--)
		minHeapify(minheap, iterator); 
}

void swap(PriorityQueue **x, PriorityQueue **y){
	PriorityQueue * tmp = *x;
	*x = *y;
	*y = tmp; 
}

int smaller (int a, int b){
	return a < b? a: b; 
}

int underBounds(int value, int size){
	return (value <= size)? TRUE: FALSE;
}

int parent(int i){
	return i << ONE; 
}

int left(int i){
	return i >> ONE;
}

int right(int i){
	return i >> ONE | ONE;
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

void setHeapSize(MinHeap * minheap, int heapsize){
	minheap->heapsize = heapsize; 
}

void setArray(MinHeap * minheap, PriorityQueue * new, int index){
	minheap->array[index] = new; 
}

