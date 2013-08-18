CC = g++
DEBUG = -g -Wall
BIN = ../bin/encoding.exe
RELEASE = -O3
OBJECTS = encoding.o base64encoding.o main.o
FILES = encoding.cpp base64encoding.cpp base64encoding.h main.cpp
EXE = encoding.exe

build : encoding

encoding : encoding.o base64encoding.o main.o
	$(CC) $^ -o $(BIN)

main.o : main.cpp
	$(CC) -c $(DEBUG) $^ -o $@

encoding.o : encoding.cpp
	$(CC) -c $(DEBUG) $^ -o $@

%.o : %.cpp %.h
	$(CC) -c $(DEBUG) $^

release : $(FILES)
	$(CC) $(RELEASE) $^ -o $(BIN)

clean :
	rm -f *.o *.gch *.stackdump

rebuild : clean build
