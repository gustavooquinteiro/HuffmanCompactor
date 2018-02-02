# Makefile do Trabalho de Estrutura de Dados e Algoritmos I - MATA40

# Nome do projeto e do executável encontrado no diretório corrente após compilação
PROJ_NAME = HuffmanCompactor

# Arquivos .c encontrados em src/
C_SOURCE = $(wildcard ./src/*.c)

# Arquivos .h encontrados em lib/
H_SOURCE = $(wildcard ./lib/*.h)

# Arquivos objetos .o encontrados em obj/ após compilação
OBJ = $(subst .c,.o,$(subst src,obj,$(C_SOURCE)))

# Compilador utilizado
# Em testes foi utilizado o: gcc (GCC) 7.2.1 20171224
CC = gcc

# Flags utilizadas na compilação
CC_FLAGS = -c \
           -g \
           -Wall \
           -Wextra \
           -Werror \
           -Wpedantic \
           -lm \

# Comando de construção de diretório
MKDIR = mkdir -p

# Comando de limpeza de alvos
RM = rm -rf

GREEN = \033[0;32m
NC = \033[0m

.PHONY: all clean

# Regras de compilação
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo -e "	Building binary $@..."
	@ $(CC) $^ -o $@
	@ echo -e "[${GREEN} OK ${NC}]  Build complete"

./obj/%.o: ./src/%.c ./lib/%.h
	@ echo -e "	Compiling $^ in $@..."
	@ $(CC) $< $(CC_FLAGS) -o $@
	@ echo -e  "[${GREEN} OK ${NC}]  Compiled"

# Regra de criação de diretório para os objetos
objFolder:
	@ echo "	Creating directory for object files..."
	@ $(MKDIR) obj
	@ echo -e -n "[${GREEN} OK ${NC}]  Created obj directory in " && pwd

# Regra de limpeza de objetos e executável
clean:
	@ echo -e "	Cleaning workspace... "
	@ $(RM) obj $(PROJ_NAME) *~
	@ echo -e "[${GREEN} OK ${NC}]  Clean workspace"

authors:
	@ echo -e "This is the list of $(PROJ_NAME) authors for copyright purposes.\nThis does not necessarily list everyone who has contributed code,\nsince in some cases, their employer may be the copyright holder.\nTo see the full list of contributors, see the revision history in source control.\n" > AUTHORS
	@ git log --raw | grep "^Author: " | sort | uniq | cut -d ' ' -f2- | sed 's/^/- /' >> AUTHORS