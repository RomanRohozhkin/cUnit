make: test.o ci-strcpy.o ci-strcat.o ci-strlen.o ci-strcmp.o ci-strstr.o ci-strtok.o
	gcc -o test test.c ci-strcpy.c ci-strcat.c ci-strlen.c ci-strcmp.c ci-strstr.c ci-strtok.c

test.o: test.c
	gcc -c test.c

ci-strcpy.o: ./src/ci-strcpy.c ./src/ci_strings.h
	gcc -c ./src/ci-strcpy.c

ci-strcat.o: ./src/ci-strcat.c ./src/ci_strings.h
	gcc -c ./src/ci-strcat.c 

ci-strlen.o: ./src/ci-strlen.c ./src/ci_strings.h 
	gcc -c ./src/ci-strlen.c

ci-strcmp.o: ./src/ci-strcmp.c ./src/ci_strings.h
	gcc -c ./src/ci-strcmp.c

ci-strstr.o: ./src/ci-strstr.c ./src/ci_strings.h
	gcc -c ./src/ci-strstr.c

ci-strtok.o: ./src/ci-strtok.c ./src/ci_strings.h
	gcc -c ./src/ci-strtok.c 

#TESTS

test:
	sh run-tests.sh

#CLEAN

clean:
	rm -rf *.o *~ \#*  test test-strlen
	find . -type f -name '*~' -delete
