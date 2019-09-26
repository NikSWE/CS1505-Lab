# compiler
CC = gcc
# compiler flags
CFLAGS = -g -Wall

.PHONY: default

# build executable
default: mealy.o moore.o dfa.o my_string.o machine.o
	$(CC) $(CFLAGS) -o machine.out moore.o mealy.o dfa.o my_string.o machine.o
	$(RM) *.o
	@echo build successful

# build objects
machine.o:
	$(CC) $(CFLAGS) -c src/machine.c

mealy.o:
	$(CC) $(CFLAGS) -c src/mealy/mealy.c

dfa.o:
	$(CC) $(CFLAGS) -c src/dfa/dfa.c

my_string.o:
	$(CC) $(CFLAGS) -c src/helper/my_string.c

moore.o:
	$(CC) $(CFLAGS) -c src/moore/moore.c

# clean
clean:
	$(RM) *.out *.o