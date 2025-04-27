PROGRAM_NAME=graph
OBJECT_FILES=*.o 
SOURCE_FILES=graph.c main.c
CLEAN=rm -f 
CC=gcc
$(PROGRAM_NAME): $(OBJECT_FILES)
	$(CC) -o $@ $^

$(OBJECT_FILES): $(SOURCE_FILES)
	$(CC) -c $^

clean:
	$(CLEAN) *.o $(PROGRAM_NAME)