#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void findInsertAndErase(std::string& fileContent, const std::string& target, const std::string& insertText)
{
	size_t						pos;
	std::string::const_iterator	it;

	it = fileContent.begin();
	while (it != fileContent.end())
	{
		pos = fileContent.find(target);
		it = it + pos;
		if (it != fileContent.end()) {
			fileContent.insert(it - fileContent.begin(), insertText);
			it += insertText.length();
			fileContent.erase(target.length());
		}
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 4) {
		std::cout << "Use: ./program <FileName> s1 s2" << std::endl;
		return (1);
	}
	std::ifstream file(argv[1]);
	std::stringstream buffer;

	buffer << file.rdbuf();
	std::string fileContent = buffer.str();

	findInsertAndErase(fileContent, (std::string)argv[2], (std::string)argv[3]);

	std::string	fileName = (std::string)argv[1] + ".replace";
	std::ofstream(fileName) << fileContent;

}

// Abra o arquivo e atribua o conteúdo a uma string