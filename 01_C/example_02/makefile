# Compilacion
CC		=	gcc
SRCCC = c_struct.c
OBJCC = c_struct.o

# Enlazado
LINKER = gcc
SRCL = c_struct.o
BINL = c_struct.out

ifeq ($(OS),Windows_NT)
	RM = del /Q
else
	RM = rm -rf
endif
# -*- Execution -*-
.PHONY: all all-before all-after
	
all: $(OBJCC) $(BINL)

$(OBJCC): $(GLOBALDEPS)
	$(CC) -c $(SRCCC) -o $(OBJCC)

$(BINL): $(OBJCC)
	$(LINKER) $(SRCL) -o $(BINL)
