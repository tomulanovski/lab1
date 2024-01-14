CFLAGS = -Wall -g
all:output

output: base.o
	gcc $(CFLAGS) base.o -o output

addresses.o: addresses.c
	gcc $(CFLAGS) -c addresses.c

count_words.o: count_words.c
	gcc $(CFLAGS) -c count_words.c

base.o: base.c
	gcc $(CFLAGS) -c base.c


clean:
	rm *.o output
