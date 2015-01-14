#include "encoding.cpp"

class Base64Encoding {
 public:
  static string encode ( const string& );
  static string decode ( const string& );

 protected:
  static int hashIndex ( const char& );
  static string hash;
};
