# AppBanco compatible con windows 10, Linux Mint y Kubuntu

# Nombre del archivo ejecutable
GBanco=Banco

OBJ=Banco.o

all: $(OBJ)
	gcc -o $(GBanco) Banco.o

Banco.o: Banco.c
	gcc -c Banco.c -I"./src"

clean:
	rm $(OBJ) $(GBanco)
