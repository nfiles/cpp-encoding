make :		encoding

encoding :	main.cpp base64encoder.o
	gcc -g main.cpp base64encoder.o -o base64encoding

encoder.o :	encoder.h encoder.cpp
	gcc -g encoder.h encoder.cpp -o encoder.o

base64encoder.o : base64encoder.h base64encoder.cpp encoder.o
	gcc -g base64encoder.h base64encoder.cpp encoder.o -o base64encoder.o

release : base64encoder.h base64encoder.cpp encoder.h encoder.cpp main.cpp
	gcc base64encoder.h base64encoder.cpp encoder.h encoder.cpp main.cpp -o base64encoder

clean :	
	rm fib
