EXECUTABLE  = generate_maze.exe
SRC_C		= src\generation.c src\main.c src\otuput.c
SRC_H		= inc\generation.h inc\output.h

$(EXECUTABLE): $(SRC_C) $(SRC_H)
	gcc -o $(EXECUTABLE)  $(SRC_C)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean: 
	del $(EXECUTABLE)

.PHONY: run clean