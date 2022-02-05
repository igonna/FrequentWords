#include "wfreq.h"

namespace wfreq { class File; }

class wfreq::File
{
private:
	std::string data;
public:
	File();
	File(std::string fileName);
	operator std::string() const;
	std::string getStringFromFile(std::string fileName);
	bool outStringToFile(std::string fileName, std::string str);
	std::string getDirectoryName(std::string fileName);
};

