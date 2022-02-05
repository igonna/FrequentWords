#include "StringTransform.h"

wfreq::StringTransform::StringTransform()
{

}

wfreq::StringTransform::StringTransform(std::string copyString)
{
	str = copyString;
}

bool wfreq::StringTransform::isAsciiChar(char c)
{
	return (90 >= static_cast<int>(c) && static_cast<int>(c) >= 65) || (122 >= static_cast<int>(c) && static_cast<int>(c) >= 97) || static_cast<int>(c) == 39;
}

bool wfreq::StringTransform::isLetter(char c)
{
	return (90 >= static_cast<int>(c) && static_cast<int>(c) >= 65) || (122 >= static_cast<int>(c) && static_cast<int>(c) >= 97);
}

std::string wfreq::StringTransform::cleanString(std::string strDirty)
{
	std::string StrClean;
	for (size_t i = 0; i < strDirty.size(); ++i)
	{
		if (str[i] == ' ')
		{
			if (i && str[i - 1] != ' ')
				StrClean += str[i];
			continue;
		}
		if (isAsciiChar(strDirty[i]))
			StrClean += strDirty[i];
	}
	return str = StrClean;
}

void wfreq::StringTransform::cleanString()
{
	cleanString(str);
}

void wfreq::StringTransform::toLower()
{
	std::transform(str.begin(), str.end(), str.begin(),
		[](unsigned char c) { return std::tolower(c); });
}

std::vector<std::string> wfreq::StringTransform::getWordsFromString(std::string str)
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

std::vector<std::string> wfreq::StringTransform::getWordsFromString()
{
	return getWordsFromString(str);
}

std::string wfreq::StringTransform::getStringFromWords(std::vector<std::string> words)
{
	str.clear();
	for (auto word : words)
		str += word + '\n';
	return str;
}

std::string wfreq::StringTransform::getString()
{
	return str;
}