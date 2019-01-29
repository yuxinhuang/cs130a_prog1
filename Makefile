#Makefile
CXX=g++
CXXFLAGS = -Wall -Wextra -Werror
BINARIES=prog1A prog1B
all: ${BINARIES}



prog1A: Hash_1.o main_1.o
	${CXX} $^ -o  $@ -std=c++11
prog1B: Hash_2.o main_2.o
	${CXX} $^ -o  $@ -std=c++11

clean:
	/bin/rm -f ${BINARIES} *.o