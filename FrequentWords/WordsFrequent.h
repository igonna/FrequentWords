#include "wfreq.h"
#include "WordScore.h"

namespace wfreq { class WordsFrequent; }



class wfreq::WordsFrequent
{
private:
	std::vector<wfreq::WordScore> words;
	size_t it;
public:
	WordsFrequent();
	WordsFrequent(std::vector<std::string> words);
	bool containsWord(std::string word);
	void addWord(std::string word);
	size_t size();
	void sortWords();
	std::vector<std::string> getWords();
	std::vector<std::string> getSortedWords();
};

