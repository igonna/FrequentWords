#include "WordsFrequent.h"

wfreq::WordsFrequent::WordsFrequent()
{
	it = 0;
}

wfreq::WordsFrequent::WordsFrequent(std::vector<std::string> wordsCopy)
{
	for (auto word : wordsCopy)
	{
		addWord(word);
	}
}

bool wfreq::WordsFrequent::containsWord(std::string word)
{
	for (size_t i = 0; i < words.size(); ++i)
	{
		if (words[it = i].str == word)
			return true;
	}
	return false;
}

void wfreq::WordsFrequent::addWord(std::string word)
{
	if (containsWord(word))
	{
		++words[it].score;
	}
	else
	{
		words.push_back(wfreq::WordScore(word, 1));
	}
}

size_t wfreq::WordsFrequent::size()
{
	return words.size();
}

void wfreq::WordsFrequent::sortWords()
{
	std::sort(words.begin(), words.end(), [](wfreq::WordScore a, wfreq::WordScore b)
		{
			return a.getScore() > b.getScore();
		});
}

std::vector<std::string> wfreq::WordsFrequent::getWords()
{
	std::vector<std::string> wordsResult;
	for (auto word : words)
	{
		wordsResult.push_back(word.getString());
	}
	return wordsResult;
}

std::vector<std::string> wfreq::WordsFrequent::getSortedWords()
{
	sortWords();
	return getWords();
}