all: hasht

hasht: third.c
	gcc -Wall -Werror -fsanitize=address third.c -o third

clean:
	rm -rf hasht
