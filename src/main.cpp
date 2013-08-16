#include <iostream>
using std::cout;
using std::endl;

#include "base64encoder.h"

int main(int argc, char *argv[]) {
	string hello = "Hello, World!";

	cout << hello << endl;
	cout << Base64Encoder::encode(hello) << endl;

	return 0;
}
