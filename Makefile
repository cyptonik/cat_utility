CC = gcc
FLAGS = -Wall -Werror -Wextra
UTILS = utils/*

all: clean cat

cat: cat.c $(UTILS)
	$(CC) $(FLAGS) $^ -o cat

clean: 
	rm -f cat
