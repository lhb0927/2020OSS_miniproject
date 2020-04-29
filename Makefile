main: main.c product.o
	gcc -o $@ $^

clean:
	rm *.o main
