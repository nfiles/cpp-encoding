#include <iostream>
using std::cout;
using std:: endl;

#include <string>
using std::string;

#include "base64encoder.h"

int main(int argc, char** argv) {
	Base64Encoder base64 = new Base64Encoder();

	string hello = "Hello, world!";
	
	cout << base64.encode(hello);

	return 0;
}
