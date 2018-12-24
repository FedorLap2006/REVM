CC=g++
all: kernelVM
kernelVM: kernelVM.o
	$(CC) -Wall kernelVM.o -o kernelVM.vexe

kernelVM.o: kernelVM.c
	$(CC) -c -Wall kernelVM.c -o kernelVM.o

run:
	./kernelVM.vexe

clean:
	rm *.o *.vexe
