#include "wfreq.h"

namespace wfreq { class WordScore; }

class wfreq::WordScore
{
public:
	std::string str;
	size_t score;
public:
	WordScore();
	WordScore(std::string copyStr, size_t n);
	std::string getString();
	size_t getScore();
	void incScore();
};
