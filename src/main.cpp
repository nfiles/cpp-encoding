#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "base64encoding.h"

int main(int argc, char *argv[]) {
  string * inputs;
  int inputs_len;

  Encoding<Base64Encoding> base64;

  if (argc > 1) {
    inputs = new string[argc - 1];
    inputs_len = argc - 1;
    for (int i = 0; i < inputs_len; ++i) {
      inputs[i] = argv[i + 1];
    }
  } else {
    inputs = new string[1];
    inputs_len = 1;
    inputs[0] = "Hello, World!";
  }

  string encoded;
  for (int i = 0; i < inputs_len; ++i) {
    cout << "Clear:   " << inputs[i] << endl;
    cout << "Encoded: " << (encoded = base64.encode(inputs[i])) << endl;
    cout << "Decoded: " << base64.decode(encoded) << endl;
    cout << endl;
  }

  delete [] inputs;

  return 0;
}
