PROGRAM_NAME=graph
OBJECT_FILES = *.o 
SOURCE_FILES=graph.c main.c
CLEAN = rm -f 

$(PROGRAM_NAME): $(OBJECT_FILES)
	gcc -o $@ $^

$(OBJECT_FILES): $(SOURCE_FILES)
	gcc -c $^

clean:
	$(CLEAN) *.o $(PROGRAM_NAME)