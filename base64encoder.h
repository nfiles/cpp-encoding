#include "encoder.h"

// class Base64Encoder : public Encoder<Base64Encoder> {
class Base64Encoder {
public:
	static string encode ( const string& );
// protected:
// 	static string encode ( const string& );

private:
	static void clearToBit ( const bits* );
	static void bitTo64    ( const bits* );

	struct bits
	{
		char* array;
		unsigned int len;
	};
};
