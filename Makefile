COMPILER=gcc

all: badapple

imagemnp.o: imagemnp.h imagemnp.c
	${COMPILER} imagemnp.c -ljpeg -c

filemnp.o: filemnp.h filemnp.c
	${COMPILER} filemnp.c -c

ascii.o: ascii.h ascii.c
	${COMPILER} ascii.c -c

badapple: imagemnp.o filemnp.o ascii.o main.c
	${COMPILER} main.c ascii.o filemnp.o imagemnp.o -ljpeg -o BadApple

clean:
	rm *.o
