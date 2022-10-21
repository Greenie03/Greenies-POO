CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -pedantic -ggdb
all : main
executable : fonctions.o main.o
	$(CC) $(CFLAGS) -o $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -C $< $(CFLAGS)
clean :
	rm *.o main
run : main
	./main
	
memoire : main
	valgrind ./main
