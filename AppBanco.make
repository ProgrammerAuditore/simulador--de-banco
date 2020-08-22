# AppBanco compatible con windows 10, Linux Mint y Kubuntu

# Nombre del archivo ejecutable
GAppBanco=AppBanco

OBJ=AppBanco.o

all: $(OBJ)
	 gcc -o $(GAppBanco) AppBanco.o
	 
AppBanco.o: AppBanco.c
	gcc -c AppBanco.c -I"./src" -std=c99
	
clean:
	rm $(OBJ) $(GAppBanco)
