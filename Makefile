EXECUTABLE  =generate_maze.exe
SRC_C		=src/generation.c src/main.c src/otuput.c
SRC_H		=inc/generation.h inc/output.h
MEM_FLAGS   =--leak-check=full  --show-leak-kinds=all --track-origins=yes --verbose

$(EXECUTABLE): $(SRC_C) $(SRC_H)
	gcc -g -Wall -ggdb3 -o $(EXECUTABLE)  $(SRC_C)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

test: $(EXECUTABLE)
	valgrind $(MEM_FLAGS) ./$(EXECUTABLE)

clean: 
	rm -f $(EXECUTABLE)

.PHONY: run clean
