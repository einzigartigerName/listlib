all: clean test

clean:
	rm -f test

test:
	$(CC) -o test test.c list.c