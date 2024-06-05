#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>

void findInsertAndErase(std::string& fileContent, const std::string& target, const std::string& insertText)
{
	size_t	pos = 0;

	while (1)
	{
		pos = fileContent.find(target, pos);
		if (pos == std::string::npos)
			break ;
		fileContent.erase(pos, target.length());
		fileContent.insert(pos, insertText);
		pos += insertText.length();
	}
}

void	fillOutFile(const std::string &fileName, const std::string& fileContent)
{
	std::ofstream	outFile;

	outFile.open(fileName.c_str(), std::ios::out | std::ios::trunc);
	outFile << fileContent;
	outFile.close();
}

int	getInFileText(std::string &fileContent, char *fileName)
{
	std::ifstream		inFile(fileName);
	std::stringstream	buffer;

	if (inFile.fail()) {
		std::cerr << "Error opening file" << std::endl;
		return (1);
	}
	buffer << inFile.rdbuf();
	fileContent = buffer.str();
	inFile.close();
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 4) {
		std::cerr << "Use: ./<program> <FileName> s1 s2" << std::endl;
		return (1);
	}
	if (!strlen(argv[2])) {
		std::cerr << "Use: s1 cannot be empty" << std::endl;
		return (1);
	}
	std::string	fileContent;
	std::string	outFileName = (std::string)argv[1] + ".replace";

	if (getInFileText(fileContent, argv[1]))
		return (1);
	findInsertAndErase(fileContent, argv[2], argv[3]);
	fillOutFile(outFileName, fileContent);
	return (0);
}
