#include<iostream>
#include<fstream>

int main() {
	std::ifstream iFile;
	iFile.open("File.txt");

	if (!iFile)
	{
		std::cerr << "File couldn't open!" << std::endl;
		return -1;
	} 

	unsigned int fileSize = 0;

	char c1;
	while (iFile.get(c1)) {
		fileSize += sizeof(c1);
		std::cout << c1;
	}
	std::cout << std::endl;

	iFile.close();

	std::cout << "Size of the file is: " << fileSize << std::endl;

	return 0;
}
