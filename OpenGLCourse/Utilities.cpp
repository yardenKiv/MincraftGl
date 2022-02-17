#include "Utilities.h"

std::string Utilities::readFile(std::string fileName)
{
	std::ifstream t(fileName);
	std::string str((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());

	return str;
}
