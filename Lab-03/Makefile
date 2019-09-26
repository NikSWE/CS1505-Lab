# compiler
CC = gcc
# compiler flags
CFLAGS = -g -Wall

.PHONY: default

# build executable
default: mealy.o dfa.o machine.o
	$(CC) $(CFLAGS) -o machine.out mealy.o dfa.o machine.o
	$(RM) *.o
	@echo build successful

# build objects
machine.o:
	$(CC) $(CFLAGS) -c src/machine.c

mealy.o:
	$(CC) $(CFLAGS) -c src/mealy/mealy.c

dfa.o:
	$(CC) $(CFLAGS) -c src/dfa/dfa.c

# clean
clean:
	$(RM) machine *.o