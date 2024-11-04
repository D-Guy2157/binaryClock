COMPILER = gcc
OPTIONS = -Wall
PROGRAM = main.out
FILES = main.c clock.c

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): $(FILES)
	$(COMPILER) $(OPTIONS) $(FILES) -o $(PROGRAM)

clean:
	rm *.out