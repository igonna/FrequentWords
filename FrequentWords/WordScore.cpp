#include "WordScore.h"

wfreq::WordScore::WordScore()
{
	str.clear();
	score = 0;
}

wfreq::WordScore::WordScore(std::string copyStr, size_t n)
{
	str = copyStr;
	score = n;
}

std::string wfreq::WordScore::getString()
{
	return str;
}

size_t wfreq::WordScore::getScore()
{
	return score;
}

void wfreq::WordScore::incScore()
{
	++score;
}
