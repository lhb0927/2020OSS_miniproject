main: main.c product.o manager.o
	gcc -W -Wall -o $@ $^

clean:
	rm *.o main
