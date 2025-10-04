CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC = src/*
BUILD = build/

all: clean cat

cat: $(SRC)
	$(CC) $(FLAGS) $^ -o $(BUILD)cat

clean: 
	rm -f $(BUILD)cat
