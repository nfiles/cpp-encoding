// Nathan Files
// Class for encoding text

#ifndef ENCODING
#define ENCODING

#include <string>
using std::string;

template<class EncodingScheme>
class Encoding {
 public:
  string encode ( const string& input ) {
    return EncodingScheme::encode(input);
  }
  string decode ( const string& input ) {
    return EncodingScheme::decode(input);
  }
};

#endif // ENCODING
