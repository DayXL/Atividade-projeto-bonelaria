run: all
	./Hat

all:
	gcc -c -Wall *.c
	gcc -o Hat *.o
clean:
	rm ./*.o

##Com base no de Lucas e Tallys

## Lucas: https://github.com/W1ndeck
## Tallys: https://github.com/Tallys-Aureliano