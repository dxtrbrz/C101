# Name of the project
PROJ_NAME=funcptr-v01

# .c files
C_SOURCE=$(wildcard *-v01.c)

# .h files
H_SOURCE=$(wildcard *-v01.h)

# Object files
OBJ=$(C_SOURCE:.c=.o)

# Compiler
CC=gcc

# Flags for compiler
CC_FLAGS=-c \
         -W \
				 -Wall \
				 -ansi \
				 -pedantic
#
# Compilation and linking
#
all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)

main.o: main.c $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -rf *~ *.i *.o *.s *.out $(PROJ_NAME)