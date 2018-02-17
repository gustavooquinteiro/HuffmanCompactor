#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/main.h"

int main(int argumentCounter, char *argumentValues[]){
	if (argumentCounter > ONE){
		register int iterator;
		for(iterator = ONE; iterator < argumentCounter; iterator++){
			char * fileName = argumentValues[iterator];
			FILE * archive = fopen(fileName, READ_MODE);
			if (!isValidFile(archive, fileName)) {
				continue;
			} else{
				if (isCompactedFile(fileName))
					decompress(archive);
				else
					compress(archive, fileName);
			}
		}
	} else
		printf(NONEXISTENT_FILE);

	exit(EXIT_SUCCESS);
}

void decompress(FILE * file){
	printf("Decompressing file...\n");
	// descompacta(file, finalFileName)
	fclose(file);
	printf("Decompressed file\n");
}

void compress(FILE * file, char * filename){
	printf("Compressing file...\n");
	strcat(filename, EXTENSION);
	compacta(file, filename);
	/*MinHeap * meu_heap = defineMinHeap(128);
	insertHeap(meu_heap, 12, 10);
	insertHeap(meu_heap, 122, 20);
	insertHeap(meu_heap, 32, 34);
	insertHeap(meu_heap, 52, 29);
	insertHeap(meu_heap, 62, 11);
	insertHeap(meu_heap, 72, 28);
	printf("VAI REMOVER\n");
	removeMinimum(meu_heap);
	printf("VAI REMOVER\n");
	removeMinimum(meu_heap);
	
	insertHeap(meu_heap, 45, 8);
	insertHeap(meu_heap, 41, 5);
	insertHeap(meu_heap, 89, 2);
	insertHeap(meu_heap, 42, 3);
	printf("VAI REMOVER\n");
	removeMinimum(meu_heap);
	printf("VAI REMOVER\n");
	removeMinimum(meu_heap);*/
	fclose(file);
	printf("Generated compressed file\n");
}

void * isValidFile(FILE * archive, char * filename){
	printf("\nValidating file: %s...", filename);
	if (!archive){
		printf(" [ ERROR ]\n");
		perror(NULL_FILE);
	} 
	printf(" [ OK ]\n");
	return archive;
}

void * isCompactedFile(char * filename){
	char * extension = strstr(filename, EXTENSION);
	if (extension && strcmp(extension, EXTENSION) == ZERO)
		return extension;
	return NULL;
}
