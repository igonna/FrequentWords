#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <streambuf>
#include <ctime>
#include <chrono>

namespace user
{
	class File
	{
	private:
		std::string Data;
	public:
		File(std::string fileName)
		{
			Data = getStringFromFile(fileName);
		}

		std::string getStringFromFile(std::string fileName)
		{
			std::ifstream ifile(fileName);
			if (!ifile)
				return std::string();

			std::ostringstream ss;
			ss << ifile.rdbuf();
			return ss.str();
		}

		operator std::string() const
		{
			return Data;
		}
	};

	class WordsFrequent
	{
	private:
		struct Word
		{
			std::string str;
			size_t n;
			Word(std::string str, size_t n)
			{
				this->str = str;
				this->n = n;
			}
		};
		std::vector<Word> WordsFrequent;
		size_t it;
	public:
		bool containsWord(std::string word)
		{
			for (size_t i = 0; i < WordsFrequent.size(); ++i)
			{
				if (WordsFrequent[it = i].str == word)
					return true;
			}
			return false;
		}
		void addWord(std::string word)
		{
			if (containsWord(word))
			{
				++WordsFrequent[it].n;

			}
			else
			{
				WordsFrequent.push_back(Word(word, 1));
			}
		}
		size_t size()
		{
			return WordsFrequent.size();
		}
		std::vector<std::string> getSortedWords()
		{
			std::sort(WordsFrequent.begin(), WordsFrequent.end(), [](Word a, Word b)
				{
					return a.n > b.n;
				});
			std::vector<std::string> wordsSorted;
			for (auto w : WordsFrequent)
			{
				wordsSorted.push_back(w.str);
			}
			return wordsSorted;
		}
	};
}




bool isAsciiChar(char c)
{
	return (90 >= static_cast<int>(c) && static_cast<int>(c) >= 65) || (122 >= static_cast<int>(c) && static_cast<int>(c) >= 97) || c == '\'';
}

std::string cleanString(std::string str, bool (*ValidChar)(char c))
{
	std::string StrClean;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] == ' ')
		{
			if (i && str[i - 1] != ' ')
				StrClean += str[i];
			continue;
		}
		if (ValidChar(str[i]))
			StrClean += str[i];
	}
	return StrClean;
}

std::vector<std::string> getWordsFromString(std::string str)
{
	std::vector<std::string> Lines;
	char SymbolEndOfLine = ' ';

	std::string Line;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] != SymbolEndOfLine)
			Line += str[i];
		else
		{
			Lines.push_back(Line);
			Line.clear();
		}
	}
	return Lines;
}



int main(int argc, char** argv)
{
	if (argc != 2)
		return 1;

	auto TimeStart = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	std::string DataDirty = user::File(argv[1]);
	DataDirty = cleanString(DataDirty, isAsciiChar);
	std::vector<std::string> Words = getWordsFromString(DataDirty);
	user::WordsFrequent WordsFrequent;

	for (auto word : Words)
	{
		WordsFrequent.addWord(word);
	}
	std::string StrWords;
	for (auto word : WordsFrequent.getSortedWords())
	{
		StrWords += word + "\n";
	}
	std::ofstream("C:/Users/c/Downloads/finalFile.txt") << StrWords;
	
	std::cout << "Words: " << Words.size() << " Freq: " << WordsFrequent.size() << std::endl;

	auto TimeExec = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - TimeStart;
	std::cout << "Execution time: " << static_cast<double>(TimeExec) / 1000.0 << " sec." << std::endl;
    return 0;
}