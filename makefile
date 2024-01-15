CFLAGS = -Wall -g
all:output

output: menu_map.o
	gcc $(CFLAGS) menu_map.o -o output

addresses.o: addresses.c
	gcc $(CFLAGS) -c addresses.c

count_words.o: count_words.c
	gcc $(CFLAGS) -c count_words.c

base.o: base.c
	gcc $(CFLAGS) -c base.c

menu_map.o: menu_map.c
	gcc $(CFLAGS) -c menu_map.c

.PHONY: clean

clean:
	rm *.o output
