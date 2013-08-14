#ifndef BASE64ENCODER_H
#define BASE64ENCODER_H

#include "base64encoder.h"

static char* Base64Encoder::encode ( const string& input ) {
	string bit_pattern = "";

	char c;
	for (string::iterator i = input.begin(); i != input.end(); i++)
	{
		c = *i;
		for (int j = 0; j < 8; ++j) {
			bit_pattern += (char)((c >> j) & 1);
		}
	}
}

#endif // BASE64ENCODER_H
