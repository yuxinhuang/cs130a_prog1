#Makefile
CXX=g++
CXXFLAGS = -Wall -Wextra -Werror
BINARIES=prog1A prog1B
all: ${BINARIES}



prog1A: Hash_1.o main_1.o
	${CXX} -std=c++11 $^ -o  $@ 
prog1B: Hash_2.o main_2.o
	${CXX} -std=c++11 $^ -o  $@ 

clean:
	/bin/rm -f ${BINARIES} *.o