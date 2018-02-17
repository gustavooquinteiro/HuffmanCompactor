#include "minheap.h"
#include "compress.h"
#ifndef MAIN_H
#define MAIN_H

#define NULL_FILE "Null file"
#define NONEXISTENT_FILE "Need file(s) to be compressed\n"
#define READ_MODE "r"
#define WRITE_MODE "w"
#define EXTENSION ".dcc"

int main (int argumentCounter, char * argumentValues[]);
void * isValidFile(FILE * archive, char * filename);
void * isCompactedFile(char * filename);
void compress(FILE * file, char * filename);
void decompress(FILE * file);

#endif
