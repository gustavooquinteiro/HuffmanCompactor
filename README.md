# HuffmanCompactor

## Propósito
Compactador de arquivos usando o algoritmo de Huffman, juntamente com o conceito de fila de prioridades, utilizando um heap mínimo, em linguagem C 

## História
David Huffman desenvolveu o método como projeto da disciplina Teoria da Informação em 1950 (Blelloch, 2001) enquanto aluno de Doutorado no MIT (Sayood, 2006)  e publicou as suas conclusões em 1952 no artigo “A Method for the Construction of Minimum-Redundancy Codes” na revista Proceedings of the I.R.E. (Huffman, 1952).
O algoritmo de Huffman assenta na Teoria de Informação de Shannon (Shannon, 1948) e no subsequente princípio de que, num elemento de informação (texto, imagem, áudio, etc.) representado por símbolos, alguns desses símbolos ocorrem mais vezes que outros. Por conseguinte, se representarmos esses símbolos mais comuns utilizando códigos mais pequenos (usando menos bits) e os símbolos menos frequentes usando códigos mais extensos (com mais bits), contrapondo à representação dos símbolos com códigos de comprimento fixo (como, por exemplo, ASCII), iremos obter uma codificação binária com menos bits, como resultado de uma diminuição do comprimento médio (em bits) de cada código (Huffman, 1952) (Pu, 2006)

Fonte: http://multimedia.ufp.pt/codecs/compressao-sem-perdas/codificacao-estatistica/algoritmo-de-huffman/ 

## Desenvolvedores
Para fins de direitos autorais, todos os desenvolvedores estão listados em [AUTHORS](https://github.com/gustavooquinteiro/HuffmanCompactor/blob/master/AUTHORS "Autores")

## Licença
Este código está sob a GNU General Public License v3.0, mais detalhes em [LICENSE](https://github.com/gustavooquinteiro/HuffmanCompactor/blob/master/LICENSE "LICENSE") 

## Histórico de Atualizações 
Todas as atualizações estão listadas em [CHANGELOG](https://github.com/gustavooquinteiro/HuffmanCompactor/blob/master/CHANGELOG "CHANGELOG")

## Modo de usar
1. Abra um terminal na pasta do compactador 
2. Compile os arquivos com o comando `make`
3. Para compactar um arquivo execute: `./HuffmanCompactor arquivo`, onde `arquivo` é o nome do arquivo a ser compactado 
> * Os arquivos compactados estarão no diretório corrente e terão a extensão `.dcc`
4. Para descompactar um arquivo execute: `./HuffmanCompactor arquivo.dcc`, onde `arquivo.dcc` é o nome do arquivo a ser descompactado
> * É possível a execução da compactação e da descompactação em múltiplos arquivos em uma única execução do compactador. Para tal, execute: `./HuffmanCompactor arquivo1 arquivo2.dcc arquivo3 arquivo4.dcc`, onde o compactador entenderá, automaticamente, quais arquivos deverão ser descompactados e quais deverão ser compactados. 
**Observação**: Coloque o nome do arquivo completo, ou seja, nome e extensão do arquivo