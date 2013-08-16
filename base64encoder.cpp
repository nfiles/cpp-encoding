#ifndef BASE64ENCODER_H
#define BASE64ENCODER_H

#include "base64encoder.h"

static char* Base64Encoder::encode ( const string& input ) {
    string bit_pattern = "";

    for (string::iterator i = input.begin(); i != input.end(); i++)
    {
        unsigned char c = *i;
        for (int j = 0; j < 7; ++j) {
            bit.append((c >> i) & 1);
        }
    }
}

string 

#endif // BASE64ENCODER_H
