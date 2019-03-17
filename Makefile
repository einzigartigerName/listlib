CFLAGS = -Wall -Wextra
SOURCE = tests/test.c src/list.c

all: clean test

test:
	$(CC) $(CFLAGS) -o $@ $(SOURCE)

clean:
	rm -f test