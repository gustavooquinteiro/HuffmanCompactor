#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "../lib/compress.h"
#include "../lib/minheap.h"

typedef struct heap{
    PriorityQueue ** array;
    int capacity;
    int heapsize;
} MinHeap;

typedef struct queue{
    int letter;
    int frequency;
    PriorityQueue * left;
    PriorityQueue * right;
} PriorityQueue;


void imprimir_arvore(PriorityQueue * arvore){
    if(arvore==NULL){
        return;
    }
    imprimir_arvore(arvore->left);
    printf("ppppppppppppppp %d\n", arvore->letter);
    imprimir_arvore(arvore->right);
}
void imprime_codigos(int matriz_conferencia[][TAMANHO_ALFABETO], FILE * file, PriorityQueue arvore, int alfabeto[], int topo){
    matriz_conferencia=matriz_conferencia;
    file=file;
    alfabeto=alfabeto;
    topo=topo;
    /*printf("*entrei\n");
    if(arvore->left != NULL){
        alfabeto[topo]=0;
        imprime_codigos(matriz_conferencia,file,arvore, alfabeto, topo+1);
    }

    if(arvore->right != NULL){
        alfabeto[topo]=1;
        imprime_codigos(matriz_conferencia, file,arvore, alfabeto, topo+1);
    }

    if(arvore->letter != 128){
        fprintf(file,"%c ", arvore->letter);
        int i;
        for(i=0;i<topo;i++){
            fprintf(file,"%d", alfabeto[i]);
            matriz_conferencia[arvore->letter][i]=alfabeto[i];
        }
        fprintf(file,"\n");
        matriz_conferencia[arvore->letter][i]='\0';
    }*/

    imprimir_arvore(&arvore);
}

long calcula_tamanho(FILE * file){
    long posicao_inicio = ftell(file);
    fseek(file, 0, SEEK_END);
    long tamanho = ftell(file);
    fseek(file, posicao_inicio, SEEK_SET);
    return tamanho;
}

void compacta(FILE * file, char * fileName){
    long tamanho;
    long quantidade_compressoes;
    FILE * saida;
    MinHeap * meu_heap = defineMinHeap(128);
    char buffer[SIZE_COMPRESSION];
    int frequencia[TAMANHO_ALFABETO]={0};
    int i;
    int c;
    //prerrogativas
    frequencia[0]=frequencia[0];
    for(i=0;i<TAMANHO_ALFABETO;i++)
        frequencia[i]=0;
    //info do cabrecalho
    tamanho=calcula_tamanho(file);
    float valor = (tamanho*1.0)/(SIZE_COMPRESSION);
    quantidade_compressoes = (int) ceil ((int)valor) + 1;

    saida = fopen(fileName, "w");
    if (saida == NULL){
        printf("erro");
        exit(1);
    }
    fprintf(saida, "%s\n", fileName);
    fprintf(saida, "%ld %ld\n",tamanho, quantidade_compressoes);
	
    while(fgets(buffer, SIZE_COMPRESSION, file) !=NULL){
        //mede frequencia do trecho
        for(i=0;i<SIZE_COMPRESSION;i++){
            if(buffer[i]=='\0'){
                break;
            }
            int teste = (int) buffer[i];
            frequencia[teste]++;
        }

        //quantidade_frequencia informa quantas letras distintas existem no alfabeto
        int quantidade_frequencia=0;
        for(c=0;c<TAMANHO_ALFABETO;c++){
            if(frequencia[c]>0){
                quantidade_frequencia++;
                printf("%d %d\n", c, frequencia[c]);
                insertHeap(meu_heap, c, frequencia[c]);
            }
        }

        fprintf(saida, "%d %d\n", TAMANHO_ALFABETO, quantidade_frequencia);

        while(getHeapSize(meu_heap) != 1){
            PriorityQueue left = removeMinimum(meu_heap);
            printf("bbbbbbbbbb%d\n", left.letter);
            PriorityQueue right = removeMinimum(meu_heap);
            printf("bbbbbbbbbb%d\n", right.letter);
            PriorityQueue dad = createDad(left,right);
            insertDadHeap(meu_heap, dad);
        }

        PriorityQueue arvore = removeMinimum(meu_heap);
        int alfabeto[TAMANHO_ALFABETO];
        int matriz_conferencia[TAMANHO_ALFABETO][TAMANHO_ALFABETO];
        int topo=0;
        imprime_codigos(matriz_conferencia, saida, arvore, alfabeto, topo);

        for(i=0;i<SIZE_COMPRESSION;i++){
            if(buffer[i]=='\0')
                break;
            int j;
            for(j=0;matriz_conferencia[(int) buffer[i]][j]!='\0';j++){
                fprintf(saida,"%d", matriz_conferencia[(int) buffer[i]][j]);
            }
        }


    }

    fclose(saida);

}
