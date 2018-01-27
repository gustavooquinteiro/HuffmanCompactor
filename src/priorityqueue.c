/*
 * priorityqueue.c
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

#include <stdio.h>
#include <stdlib.h>
#include "../lib/priorityqueue.h"

typedef struct queue{
	char letter;
	int frequency; 
} PriorityQueue; 

PriorityQueue * definePriorityQueue (int capacity){
	PriorityQueue * new = (PriorityQueue *)malloc(capacity * sizeof(PriorityQueue));
	return new;
}

void insertKey(char letter, int frequency, MinHeap * minheap){
	int heapsize = getHeapSize(minheap); 
	
	if (heapsize == getCapacity(minheap))
		return;

	heapsize++;
		
	int index = heapsize--;
	PriorityQueue * new = getArrayIn(minheap, index); 
	new.letter = letter;
	new.frequency = frequency;
	
	setArray(minheap, new, index); 
	setHeapSize(minheap, heapsize);
	 
	buildMinHeap(minheap, heapsize); 
}


int getFrequency(PriorityQueue * queue){
	return queue.frequency; 
}

char getLetter(PriorityQueue * queue){
	return queue.letter;
}
