// Nathan Files
// Base type for encoding objects

#include <string>
using std::string;

#include <vector>
using std::vector;

template<typename DerivedType>
class Encoder {
public:
	static string encode ( const string& );
};
