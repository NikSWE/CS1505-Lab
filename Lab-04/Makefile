CC = gcc
CFLAGS = -g -Wall

.PHONY: default clean

# build executable
default: machine.o my_string.o
	$(CC) $(CFLAGS) -o machine.out machine.o my_string.o
	$(RM) *.o
	@echo build successful

# build objects
machine.o:
	$(CC) $(CFLAGS) -c src/machine.c

my_string.o:
	$(CC) $(CFLAGS) -c src/helper/my_string.c

clean:
	$(RM) *.out *.o