all: vinileria.exe

vinileria.exe: liblistas.a libfilas.a libpilhas.a
	gcc vinileria.c* -I./Bibliotecas -L./Bibliotecas -llistas -lfilas -lpilhas -o vinileria.exe

liblistas.a: listas.o
	ar -cru liblistas.a ./Bibliotecas/listas.o
	mv liblistas.a ./Bibliotecas

listas.o:
	gcc -c ./Bibliotecas/listas.c* -o listas.o
	mv listas.o ./Bibliotecas

libfilas.a: filas.o
	ar -cru libfilas.a ./Bibliotecas/filas.o
	mv libfilas.a ./Bibliotecas

filas.o:
	gcc -c ./Bibliotecas/filas.c* -o filas.o
	mv filas.o ./Bibliotecas

libpilhas.a: pilhas.o
	ar -cru libpilhas.a ./Bibliotecas/pilhas.o
	mv libpilhas.a ./Bibliotecas

pilhas.o:
	gcc -c ./Bibliotecas/pilhas.c* -o pilhas.o
	mv pilhas.o ./Bibliotecas

clean:
	rm Biblioteca/*.a Biblioteca/*.o
