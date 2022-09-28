test: alg2.o alg1.o rand_string.o benchmark.o test.o
	gcc -Wall -o test test.o alg1.o alg2.o rand_string.o benchmark.o -lm

rand_string.o: rand_string.c
	gcc -c -Wall rand_string.c -lm

alg2.o: alg2.c
	gcc -c -Wall alg2.c

alg1.o: alg1.c
	gcc -Wall -c alg1.c
	
benchmark.o: benchmark.c
	gcc -Wall -c benchmark.c -lm

test.o: test.c
	gcc -Wall -c test.c

clean:
	rm -f *.o test
