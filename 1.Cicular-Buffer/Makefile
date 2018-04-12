# Reference link: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC=gcc

CFLAGS=-Wall

DEPS = cbuff.h

OBJ = main.o cbuff.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f ./*.o main
