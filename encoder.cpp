// Nathan Files
// implementation for Encoder class

#ifndef ENCODER_H
#define ENCODER_H

#include "encoder.h"

template<typename DerivedType>
static string Encoder::encode ( const string& input ) {
	return DerivedType::encode(input);
}

#endif // ENCODER_H
