CC = g++
DEBUG = -g
VPATH = src/
BIN = bin/
SRC = src/
OBJECTS = encoder.o base64encoder.o main.o
FILES = encoder.cpp encoder.h base64encoder.cpp base64encoder.h main.cpp
EXE = encoding.exe

build : $(OBJECTS)
	$(CC) $(DEBUG) $? -o $(BIN)$(EXE)

main.o : main.cpp
	$(CC) -c $(DEBUG) $?

%.o : %.h %.cpp
	$(CC) -c $(DEBUG) $?

release : $(FILES)
	$(CC) $^ -o $(BIN)$(EXE)

clean :
	rm -f $(SRC)*.o $(SRC)*.gch $(BIN)*.exe

rebuild : clean build
