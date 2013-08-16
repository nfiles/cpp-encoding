#ifndef BASE64ENCODER_H
#define BASE64ENCODER_H

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "base64encoder.h"

string Base64Encoder::hash = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

string Base64Encoder::encode ( const string& input ) {
    string bit_pattern = "";

	#define CHECK_BIT(var,pos) (bool)((var) & (1<<(pos)))
    // bits
    for (int i = 0; i < input.length(); ++i)
    {
    	for (int b = 7; b >= 0; --b) {
    		bit_pattern += CHECK_BIT(input[i], b) ? '1' : '0';
    	}
	    // bitset<8> bits(input[i]);
        // bit_pattern += bits.to_string();
    }
	#undef CHECK_BIT

    // index
    string index = "";
    int num;
    for (int i = 0; i * 6 < bit_pattern.length(); ++i) {
    	num = 0;
    	for (int j = 0; j < 6 && i * 6 + j < bit_pattern.length(); ++j) {
    		num += ((int)bit_pattern[i * 6 + j] << j);
    	}
    	// index += hash.at(num);
    }

    return bit_pattern;
}

#endif // BASE64ENCODER_H
