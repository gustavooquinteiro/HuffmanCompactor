#include <stdio.h>
#include <stdlib.h>
#include "../lib/main.h"

int main(int argc, char *argv[]){
	if (argc > ONE){
		register int iterator;
		for(iterator = ONE; iterator < argc; iterator++){
			FILE * archive = fopen(argv[iterator], READ_MODE); 
			if (!archive) {
				perror(NULL_FILE);
				exit(EXIT_FAILURE);
			} else{
				printf("Compacting file %s...\n", argv[iterator]);
				// FILE * compressedFile;
				// compressedFile = compacta(argv[iterator]);
				// char * compressedFileName = getName(); 
				fclose(archive);
				printf("Generated compressed file %s\n", argv[iterator]);
			}
		}
	} else
		printf(NONEXISTENT_FILE);

	exit(EXIT_SUCCESS);
}
