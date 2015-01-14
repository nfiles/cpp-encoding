CC = g++
BIN = ../bin/encoding.exe

DEBUG = -g -Wall
RELEASE = -O3

OBJECTS = encoding.o base64encoding.o main.o
NOHEADER = main.o encoding.o
FILES = encoding.cpp base64encoding.cpp base64encoding.h main.cpp
TEMP = *.o *.gch *.stackdump

build : $(OBJECTS)
	$(CC) $^ -o $(BIN)

main.o : main.cpp
encoding.o : encoding.cpp
$(NOHEADER) :
	$(CC) -c $(DEBUG) $^

%.o : %.cpp %.h
	$(CC) -c $(DEBUG) $^

release : $(FILES)
	$(CC) $(RELEASE) $^ -o $(BIN)

clean :
	rm -f $(TEMP) $(BIN)

rebuild : clean build
