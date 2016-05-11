# Programe las funciones sort, compare_file_lines y swap_file_lines
# en el archivo sort.c.  Debe respetar los encabezados indicados en sort.h.
# Luego compile y ejecute con el comando:
#   $ make
# Se le felicitara si su tarea funciona correctamente

CFLAGS= -g -Wall -pedantic -std=c99
LDFLAGS= -g

all: test-sort run

sort.o test-sort.o: sort.h

test-sort: sort.o test-sort.o

run:
	sh run-test

clean:
	rm -f *.o test-sort people-sort.txt test-out.txt
