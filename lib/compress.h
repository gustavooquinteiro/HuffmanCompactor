#ifndef COMPRESS_H
#define COMPRESS_H

#define SIZE_COMPRESSION 512000
#define TAMANHO_ALFABETO 128

void compacta(FILE * file, char * fileName);
long calcula_tamanho(FILE * file);
#endif
