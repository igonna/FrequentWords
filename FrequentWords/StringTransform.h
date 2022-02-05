#include "wfreq.h"

namespace wfreq { class StringTransform; }

class wfreq::StringTransform
{
private:
	std::string str;
public:
	StringTransform();
	StringTransform(std::string copyString);
	bool isAsciiChar(char c);
	bool isLetter(char c);
	std::string cleanString(std::string str);
	//std::string cleanString(std::string str, bool (StringTransform::* ValidChar)(char c));
	void cleanString();
	void toLower();
	std::vector<std::string> getWordsFromString(std::string str);
	std::vector<std::string> getWordsFromString();
	std::string getStringFromWords(std::vector<std::string> words);
	std::string getString();
};
