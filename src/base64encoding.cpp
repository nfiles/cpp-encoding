// Nathan Files
// implementation of Base64Encoding class

#ifndef BASE64ENCODING_H
#define BASE64ENCODING_H

#include "base64encoding.h"

string Base64Encoding::hash = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

string Base64Encoding::encode ( const string& input ) {
  string bit_pattern = "";

#define CHECK_BIT(var,pos) (bool)((var) & (1<<(pos)))
  // bits
  for (unsigned int i = 0; i < input.length(); ++i) {
    for (int b = 7; b >= 0; --b) {
      bit_pattern += CHECK_BIT(input[i], b) ? '1' : '0';
    }
  }
#undef CHECK_BIT

  // encoded
  string encoded = "";
  int index; // index in base64 hash
  for (unsigned int i = 0; i * 6 < bit_pattern.length(); ++i) {
    index = 0;
#define IS_ONE(c) (c =='1' ? 1 : 0)
    for (unsigned int j = 0; j < 6 && i * 6 + j < bit_pattern.length(); ++j) {
      index += (IS_ONE(bit_pattern[i * 6 + j]) << (5 - j));
    }
#undef IS_ONE
    encoded += Base64Encoding::hash[index];
  }

  // padding
  int num_pads = input.length() % 3;
  if (num_pads) {
    encoded += (num_pads == 1 ? "==" : "=");
  }

  return encoded;
}

string Base64Encoding::decode ( const string& input ) {
  string bit_pattern = "";

  // convert each character to its numeric value according to the hash
  unsigned int index;
#define CHECK_BIT(var,pos) (bool)((var) & (1 << pos))
  for (unsigned int i = 0; i < input.length(); ++i) {
    if (input[i] == '=') continue;

    index = hashIndex(input[i]);
    for (unsigned int j = 0; j < 6; ++j) {
      bit_pattern += (CHECK_BIT(index, (5-j)) ? '1' : '0');
    }
  }
#undef CHECK_BIT

  // create original characters from bits
  string clear;
  for (unsigned int i = 0; i * 8 < bit_pattern.length(); ++i) {
    index = 0;
    for (unsigned int j = 0; j < 8 && i * 8 + j < bit_pattern.length(); ++j) {
      index += ((bit_pattern[i * 8 + j] == '1' ? 1 : 0) << (7-j));
    }
    clear += index;
  }

  return clear;
}

int Base64Encoding::hashIndex ( const char& c ) {
  if (c >= '0') {
    if (c <= '9') {
      // 0..9
      return (int)c - '0' + 52;
    }
    else if (c >= 'A') {
      if (c <= 'Z') {
        // A..Z
        return (int)c - 'A';
      }
      else if (c >= 'a' && c <= 'z') {
        // a..z
        return (int)c - 'a' + 26;
      }
    }
  }
  else if (c == '+') {
    return 62;
  }
  else if(c == '/') {
    return 63;
  }

  return -1;
}

#endif // BASE64ENCODING_H
