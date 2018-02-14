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
	
	// descompacta(file, filename)
	fclose(file);
	printf("Decompressed file\n\n");
}

void compress(FILE * file, char * filename){
	printf("Compressing file...\n");
	strcat(filename, EXTENSION);
	compacta(file, filename);
	fclose(file);
	printf("Compressed file\n\n");
}

int isValidFile(FILE * archive, char * filename){
	printf("\nValidating file: %s...", filename);
	if (!archive) {
		printf(" [ ERROR ]\n");
		perror(NULL_FILE);
		return FALSE;
	}
	printf(" [ OK ]\n");
	return TRUE;

}

int isCompactedFile(char * filename){
	char * extension = strstr(filename, EXTENSION);
	if (extension && strcmp(extension, EXTENSION)== ZERO)
		return TRUE;
	return FALSE;
}
