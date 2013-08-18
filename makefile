CC = g++
DEBUG = -g -Wall
SRC = src
BIN = bin/encoding.exe
RELEASE = -O3
OBJECTS = encoding.o base64encoding.o main.o
FILES = encoding.cpp base64encoding.cpp base64encoding.h main.cpp
EXE = encoding.exe

build :
	make -C $(SRC) build

# encoding : encoding.o base64encoding.o main.o
# 	$(CC) $^ -o $(BIN)

# main.o : main.cpp
# 	$(CC) -c $(DEBUG) $^ -o $@

# encoding.o : encoding.cpp
# 	$(CC) -c $(DEBUG) $^ -o $@

# %.o : %.cpp %.h
# 	$(CC) -c $(DEBUG) $^

release :
	make -C $(SRC) release

clean :
	rm -f *.o *.gch *.stackdump
	make -C $(SRC) clean

rebuild : clean build
