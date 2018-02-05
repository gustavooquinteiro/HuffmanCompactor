# HuffmanCompactor
Compactador de arquivos usando o algoritmo de Huffman, juntamente com o conceito de fila de prioridades, utilizando um heap mínimo, em linguagem C 

## Modo de usar
1. Abra um terminal na pasta do compactador 
2. Compile os arquivos com `make`
3. Para compactar um arquivo execute: `./HuffmanCompactor arquivo`, onde `arquivo` é o nome do arquivo a ser compactado 
> * Os arquivos compactados estarão no diretório corrente e terão a extensão `.dcc`
4. Para descompactar um arquivo execute: `./HuffmanCompactor arquivo.dcc`, onde `arquivo.dcc` é o nome do arquivo a ser descompactado
> * É possível a execução da compactação e da descompactação em múltiplos arquivos em uma única execução do compactador. Para tal, execute: `./HuffmanCompactor arquivo1 arquivo2.dcc arquivo3 arquivo4.dcc`, onde o compactador entenderá, automaticamente, quais arquivos serão descompactados e quais serão compactados.

*Observação*: Coloque o nome do arquivo completo, ou seja, nome e extensão do arquivo