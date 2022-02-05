#include <chrono>

#include "File.h"
#include "StringTransform.h"
#include "WordsFrequent.h"

int main(int argc, char** argv)
{
	if (argc != 2)
		return 1;

	auto TimeStart = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	std::string fileNameIn = argv[1];
	std::string fileNameOut = std::string(argv[1]) + ".Result.txt";
	wfreq::File file;

	wfreq::StringTransform StringTransform(file.getStringFromFile(fileNameIn));
	StringTransform.toLower();
	StringTransform.cleanString();

	wfreq::WordsFrequent WordsFrequent(StringTransform.getWordsFromString());
	file.outStringToFile(/*file.getDirectoryName(fileNameIn)*/ fileNameOut, StringTransform.getStringFromWords(WordsFrequent.getSortedWords()));

	auto TimeExec = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - TimeStart;
	std::cout << std::endl << "Path: " << fileNameOut << std::endl;
	std::cout << "Execution time: " << static_cast<double>(TimeExec) / 1000.0 << " sec." << std::endl;
    return 0;
}