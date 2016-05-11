CFLAGS= -g -Wall -pedantic -std=c99

ALL=test-parte-a test-parte-b

all: $(ALL)

test-parte-a: parte-a.o test-parte-a.o

test-parte-b: parte-a.o parte-b.o test-parte-b.o

parte-a.o parte-b.o test-parte-a.o test-parte-b.o: t2.h

clean:
	rm -f *.o $(ALL)
