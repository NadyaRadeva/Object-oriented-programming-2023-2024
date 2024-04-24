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

	char c1;
	while (iFile.get(c1)) {
		std::cout << c1;
	}

	iFile.close();

	return 0;
}
