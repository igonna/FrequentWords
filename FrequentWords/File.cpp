#include "File.h"

wfreq::File::File()
{

}

wfreq::File::File(std::string fileName)
{
	data = getStringFromFile(fileName);
}

wfreq::File::operator std::string() const
{
	return data;
}

std::string wfreq::File::getStringFromFile(std::string fileName)
{
	std::ifstream ifile(fileName);
	if (!ifile)
		return std::string();

	std::ostringstream ss;
	ss << ifile.rdbuf();
	return data = ss.str();
}

bool wfreq::File::outStringToFile(std::string fileName, std::string str)
{
	std::ofstream out(fileName);
	if (!out)
		return false;
	out << str;
	return true;
}

std::string wfreq::File::getDirectoryName(std::string fileName)
{
	char slashLeft = '\\';
	char slashRight = '/';
	size_t lastSlash = 0;
	char usedSlash = ' ';
	for (size_t i = 0; i <= fileName.size(); ++i)
	{
		if (fileName[i] == slashLeft || fileName[i] == slashRight)
		{
			lastSlash = i;
			if (fileName[i] == slashLeft)
				usedSlash = slashLeft;
			if (fileName[i] == slashRight)
				usedSlash = slashRight;
		}
	}
	return fileName.substr(0, lastSlash) + usedSlash;
}