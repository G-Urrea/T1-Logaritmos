files:=alg1.o alg2.o rand_string.o benchmark.o test.o
flags:=-c -flto -Wall

test: ${files}
	gcc -flto -O -o  test ${files} -lm 

rand_string.o: rand_string.c
	gcc ${flags} rand_string.c -lm

alg2.o: alg2.c
	gcc ${flags} alg2.c

alg1.o: alg1.c
	gcc ${flags} alg1.c
	
benchmark.o: benchmark.c
	gcc ${flags} benchmark.c -lm

test.o: test.c
	gcc ${flags} test.c

clean:
	rm -f *.o test
