# Inviroment input
ROWS := 25
COLS := 25

# Variables
EXECUTABLE      = generate_maze.exe
EXECUTABLE_GCOV = generate_maze_cov.exe
ARGS            = $(ROWS) $(COLS)
SRC_C           = src/generation.c src/main.c src/otuput.c
SRC_H           = inc/generation.h inc/output.h

# SYSTEM
SHELL           =/bin/bash
CC              =gcc
CFLAGS          =-g -std=c11 -Wall -Wvla -Werror -pedantic -ggdb3
MEM_FLAGS       =--leak-check=full  --show-leak-kinds=all --track-origins=yes --verbose
CFLAGS_GCOV     =$(CFLAGS) -fprofile-arcs -ftest-coverage
OUT				=echo -e -n

# Rules
$(EXECUTABLE): $(SRC_C) $(SRC_H)
	$(CC) $(CFLAGS) -o $(EXECUTABLE)  $(SRC_C)

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(ARGS)

test: $(EXECUTABLE)
	valgrind $(MEM_FLAGS) ./$(EXECUTABLE) $(ARGS)

coverage: $(SRC_C) $(SRC_H)
	$(CC) $(CFLAGS_GCOV) -o $(EXECUTABLE_GCOV) $(SRC_C)
	./$(EXECUTABLE_GCOV)
	gcov -f $(SRC_C)

clean:
	$(OUT) "Files removed on clean: "
	rm -vf $(EXECUTABLE) $(EXECUTABLE_GCOV) *.c.gcov *.gcno *.gcda | wc -l

.PHONY: run test coverage clean 

.SILENT: run test coverage clean
