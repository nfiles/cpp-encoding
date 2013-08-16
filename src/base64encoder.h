#include "encoder.h"

class Base64Encoder : Encoder<Base64Encoder> {
protected:
    static string encode ( const string& );

private:
	static string hash;
};
