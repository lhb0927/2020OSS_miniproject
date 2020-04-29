main: main.c product.o
	gcc -W -Wall -o $@ $^

clean:
	rm *.o main
