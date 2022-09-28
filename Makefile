test: alg2.o rand_string.o benchmark.o
	gcc -Wall -o test alg2.o rand_string.o benchmark.o -lm

rand_string.o: rand_string.c
	gcc -c -Wall rand_string.c 
alg2.o: alg2.c
	gcc -c -Wall alg2.c

alg1.o: alg1.c
	gcc -Wall -c xd.c
	
benchmark.o: benchmark.c
	gcc -Wall -c benchmark.c -lm
